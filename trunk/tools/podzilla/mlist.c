/*
 * Todo:
 * 	- make static menus dynamicable
 * 	o invert colors rather than setting them..
 *	o end line with an elipsces if wider than screen?
 * 	o multiple item selection and handling
 * 	
 * Thoughts:
 * 	o window effects? fade, disolve, slide, zoom, rotate, etc.
 * 	o sort by popularity/usage?
 *
 * Then, of course, comes integration..
 *
 * Copyright (C) 2005 Courtney Cavin
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "pz.h"
#include "ipod.h"
#include "mlist.h"

#define DEBUG

#ifdef DEBUG
#define Dprintf printf
#else
#define Dprintf(...)
#endif

void menu_draw_timer(menu_st *menulist)
{
	char *c = strdup(">");
	if(menulist->items[menulist->sel].text_width >
			menulist->w - (8 + (menulist->scrollbar ? 8 : 0))) {
		int item, diff, move;
		item = menulist->sel - menulist->top_item;
		diff = (menulist->items[menulist->sel].text_width + 8) -
			(menulist->w - (8 + (menulist->scrollbar ? 8 : 0)));
		menulist->timer_step++;
		move = (!((menulist->timer_step / diff) % 2) ?
			(menulist->timer_step % diff) :
			(diff - (menulist->timer_step % diff)));
		/* xor the pixmap */
		GrSetGCMode(menulist->menu_gc, GR_MODE_XOR);
#ifndef IPOD	/* I assume this strangeness has something to do with the color
		 * inverting differences in the microwindows drivers for x11
		 * and the ipod */
		GrSetGCForeground(menulist->menu_gc, WHITE);
#endif
		GrFillRect(menulist->pixmaps[menulist->pixmap_pos[item]],
				menulist->menu_gc, move, 0,
				menulist->w, menulist->height);
		GrCopyArea(menulist->menu_wid, menulist->menu_gc, menulist->x,
				(item * menulist->height) + menulist->y,
				menulist->w - (menulist->scrollbar ? 8 : 0),
				menulist->height,
				menulist->pixmaps[menulist->pixmap_pos[item]],
				move, 0, 0);
		/* un umm xor the pixmap */
		GrFillRect(menulist->pixmaps[menulist->pixmap_pos[item]],
				menulist->menu_gc, move, 0,
				menulist->w, menulist->height);
		GrSetGCMode(menulist->menu_gc, GR_MODE_SET);
#ifndef IPOD /* see above ifndef */
		GrSetGCForeground(menulist->menu_gc, BLACK);
#endif		
		return;
	}
	GrSetGCUseBackground(menulist->menu_gc, GR_FALSE);
	/* cycle through colors */
	if(menulist->timer_step == 0 || menulist->timer_step == 12) {
		GrSetGCForeground(menulist->menu_gc, BLACK);
		if(menulist->timer_step == 12)
			menulist->timer_step = 1;
		else
			menulist->timer_step++;
	}
	else if(menulist->timer_step == 1 || menulist->timer_step == 11) {
		GrSetGCForeground(menulist->menu_gc, GRAY);
		menulist->timer_step++;
	}
	else if(menulist->timer_step == 2 || menulist->timer_step == 10) {
		GrSetGCForeground(menulist->menu_gc, LTGRAY);
		menulist->timer_step++;
	}
	else if(menulist->timer_step >= 3 && menulist->timer_step < 10) {
		GrSetGCForeground(menulist->menu_gc, WHITE);
		menulist->timer_step++;
	}
	/* executable instead */
	if(EXECUTE_MENU & menulist->items[menulist->sel].op)
		*c = 'x';
	/* double; with a 1px offset for bold */
	GrText(menulist->menu_wid, menulist->menu_gc, menulist->x +
			(menulist->w - 8) - 6, menulist->height *
			(menulist->sel - menulist->top_item) + menulist->y + 2,
			c, -1, GR_TFASCII | GR_TFTOP);
	GrText(menulist->menu_wid, menulist->menu_gc, menulist->x +
			(menulist->w - 8) - 7, menulist->height *
			(menulist->sel - menulist->top_item) + menulist->y + 2,
			c, -1, GR_TFASCII | GR_TFTOP);
	GrSetGCForeground(menulist->menu_gc, BLACK);
	GrSetGCUseBackground(menulist->menu_gc, GR_TRUE);

	free(c);
}

/* checks the selected item for timer worthy features */
void menu_handle_timer(menu_st *menulist, int force)
{
	item_st *item;
	item = &menulist->items[menulist->sel];
	/* is a submenu item or is wider than the screen */
	if((SUB_MENU_HEADER & item->op || item->text_width > menulist->w -
			(8 * 2) || ARROW_MENU & item->op || EXECUTE_MENU &
			item->op) && !force) {
		if(!menulist->timer)
			menulist->timer =
				GrCreateTimer(menulist->menu_wid, 150);
		menulist->timer_step = 0;
	}
	/* the timer needs destroying */
	else if(menulist->timer) {
		GrDestroyTimer(menulist->timer);
		menulist->timer = 0;
		menulist->timer_step = 0;
	}
}

/* draws the scrollbar; calculates it and all */
void menu_draw_scrollbar(menu_st *menulist)
{
	int per = menulist->screen_items * 100 / menulist->num_items;
	int height = (menulist->h - 2) * (per < 3 ? 3 : per) / 100;
	int y_top = ((((menulist->h - 3) - height) * 100) * menulist->sel /
			(menulist->num_items - 1)) / 100 + 2;
	int y_bottom = y_top + height;

	/* only draw if appropriate */
	if(menulist->screen_items >= menulist->num_items)
		return;

	/* draw the containing box */
	GrRect(menulist->menu_wid, menulist->menu_gc, menulist->w - 8,
			menulist->y, 8, menulist->h - 1);
	GrSetGCForeground(menulist->menu_gc, WHITE);
	/* erase the scrollbar */
	GrFillRect(menulist->menu_wid, menulist->menu_gc, menulist->w - (8 - 1),
			menulist->y + 1, (8 - 2), y_top - (menulist->y + 1));
	GrFillRect(menulist->menu_wid, menulist->menu_gc, menulist->w - (8 - 1),
			y_bottom, (8 - 2), (menulist->h - 3) - y_bottom);
	GrSetGCForeground(menulist->menu_gc, GRAY);
	/* draw the bar */
	GrFillRect(menulist->menu_wid, menulist->menu_gc, menulist->w -
			(8 - 1), y_top, (8 - 2), height);
	GrSetGCForeground(menulist->menu_gc, BLACK);
}

/* clears specified pixmap, (GrClearWindow doesnt work properly for a pixmap) */
void menu_clear_pixmap(menu_st *menulist, int pos)
{
	if(pos < 0 || pos > menulist->screen_items - 1) {
		Dprintf("menu_clear_pixmap::No Such Pixmap\n");
		return;
	}
	GrSetGCForeground(menulist->menu_gc, WHITE);
	GrFillRect(menulist->pixmaps[menulist->pixmap_pos[pos]],
			menulist->menu_gc, 0, 0, 220, menulist->height);
	GrSetGCForeground(menulist->menu_gc, BLACK);
}

/* draws the pixmap on the screen; should probably be menu_draw_pixmap() */
/* this would be much cleaner if raster ops worked properly; perhaps I just
 * misunderstand how they are supposed to be used */
void menu_draw_item(menu_st *menulist, int item)
{
	if(item < 0 || item > menulist->screen_items - 1) {
		Dprintf("menu_draw_item::No Such Pixmap\n");
		return;
	}
	/* xor the pixmap */
	if(item == (menulist->sel - menulist->top_item)) {
		GrSetGCMode(menulist->menu_gc, GR_MODE_XOR);
#ifndef IPOD	/* I assume this strangeness has something to do with the color
		 * inverting differences in the microwindows drivers for x11
		 * and the ipod */
		GrSetGCForeground(menulist->menu_gc, WHITE);
#endif
		GrFillRect(menulist->pixmaps[menulist->pixmap_pos[item]],
				menulist->menu_gc, 0, 0, menulist->w,
				menulist->height);
	}
	GrCopyArea(menulist->menu_wid, menulist->menu_gc, menulist->x,
			(item * menulist->height) + menulist->y,
			menulist->w - (menulist->scrollbar ? 8 : 0),
			menulist->height,
			menulist->pixmaps[menulist->pixmap_pos[item]],
			0, 0, 0);
	/* un umm xor the pixmap */
	if(item == (menulist->sel - menulist->top_item)) {
		GrFillRect(menulist->pixmaps[menulist->pixmap_pos[item]],
				menulist->menu_gc, 0, 0, menulist->w,
				menulist->height);
		GrSetGCMode(menulist->menu_gc, GR_MODE_SET);
#ifndef IPOD /* see above ifndef */
		GrSetGCForeground(menulist->menu_gc, BLACK);
#endif
	}
}

/* simply erases and redoes the text on the pixmap */
void menu_retext_pixmap(menu_st *menulist, int pixmap, item_st *item)
{
	if(pixmap < 0 || pixmap > menulist->screen_items - 1) {
		Dprintf("menu_retext_pixmap::No Such Pixmap\n");
		return;
	}
	if(item < 0) {
		Dprintf("menu_retext_pixmap::Item non-existent\n");
		return;
	}
	menu_clear_pixmap(menulist, pixmap);
	GrText(menulist->pixmaps[menulist->pixmap_pos[pixmap]],
			menulist->menu_gc, 8, 1, item->text, -1, GR_TFASCII|
			GR_TFTOP);
	
	if(BOOLEAN_MENU & item->op) {
		GR_SIZE width, height, base;
		char option[4];
		/* get setting info */
		if(item->setting != 0)
			item->sel_option = ipod_get_setting(item->setting);
		/* draw boolean text */	
		strcpy(option, (item->sel_option ? "On" : "Off"));
		GrGetGCTextSize(menulist->menu_gc, option, -1, GR_TFASCII,
				&width,	&height, &base);
		GrText(menulist->pixmaps[menulist->pixmap_pos[pixmap]],
				menulist->menu_gc, (menulist->w - width) -
				(8 + 2), 1, option, -1, GR_TFASCII| GR_TFTOP);
	}
	else if(OPTION_MENU & item->op) {
		GR_SIZE width, height, base;
		char **option;
		/* get setting info */
		if(item->setting != 0)
			item->sel_option = ipod_get_setting(item->setting);
		/* draw option text */
		option = (char **)item->action;
		GrGetGCTextSize(menulist->menu_gc, option[item->sel_option],
				-1, GR_TFASCII,	&width,	&height, &base);
		GrText(menulist->pixmaps[menulist->pixmap_pos[pixmap]],
				menulist->menu_gc, (menulist->w - width) -
				(8 + 2), 1, option[item->sel_option], -1,
				GR_TFASCII | GR_TFTOP);
	}
	
	/* set the bit for a checked long item */
	if(!(LONG_ITEM & item->op)) {
		GR_SIZE width, height, base;
		GrGetGCTextSize(menulist->menu_gc, item->text,
			-1, GR_TFASCII,	&width,	&height, &base);
		item->text_width = width;

		item->op |= LONG_ITEM; 
	}

	menu_draw_item(menulist, pixmap);
}

/* does the drawing, safe(and recommended) to use {in, as} an exposure event */
void menu_draw(menu_st *menulist)
{
	int i;
	/* first draw; init onscreen text items */
	if(menulist->init == 0) {
		for(i = (menulist->num_items > menulist->screen_items) ?
				menulist->screen_items : menulist->num_items;
				i; i--)
			menu_retext_pixmap(menulist, i - 1,
					&menulist->items[i - 1]);
		menulist->init = 1;
	}
#if 0
	else if(menulist->lastsel == menulist->sel) {
		Dprintf("Aborted draw because %d == %d\n", menulist->sel,
				menulist->lastsel);
		return;
	}
	Dprintf("Continuing, %d != %d\n", menulist->sel, menulist->lastsel);
#endif
	/* draw each pixmap */
	for(i = 0; i < menulist->screen_items; i++)
		menu_draw_item(menulist, i);

	/* erase the bottom unused part of the allocated screen */
	GrSetGCForeground(menulist->menu_gc, WHITE);
	GrFillRect(menulist->menu_wid, menulist->menu_gc, menulist->x,
			menulist->height * menulist->screen_items, menulist->w,
			menulist->h - (menulist->height *
			menulist->screen_items));
	GrSetGCForeground(menulist->menu_gc, BLACK);

	/* draw scrollbar if needed */
	if(menulist->num_items > menulist->screen_items) {
		menulist->scrollbar = 1;
		menu_draw_scrollbar(menulist);
	}
	else
		menulist->scrollbar = 0;

	/* deal with the timer */
	menu_handle_timer(menulist, 0);

	menulist->lastsel = menulist->sel;
}
/* draws pixmaps starting at pos a, going to pos b; sofar unused/untested */
void menu_draw_range(menu_st *menulist, int a, int b)
{
	int i;
	if((a > menulist->screen_items - 1 || a < 0)
			|| (b > menulist->screen_items - 1 || b < 0)) {
		Dprintf("menu_draw_range::Invalid range\n");
		return;
	}
	for(i = a; (a > b ? (i >= b) : (i <= b)); (a > b ? i-- : i++))
		menu_draw_item(menulist, i);
}

/* selects specified item */
void menu_select_item(menu_st *menulist, int sel)
{
	int diff, i, j, tmp;
	
	/* if it goes off the end either way, do nothing */
	if(sel > menulist->num_items - 1 || sel < 0)
		return;

	/* the difference in select */
	diff = sel - menulist->top_item;

	/* set selected */
	menulist->sel = sel;
	
	/* if sel is below the visible screen */
	if(diff > (menulist->screen_items - 1)) {
		/* set top item */
		menulist->top_item = sel - (menulist->screen_items - 1);
		/* for each time the screen shifts down, rotate the pixmaps */
		for(j = diff - (menulist->screen_items - 1); j > 0; j--) {
			tmp = menulist->pixmap_pos[0];
			for(i = 0; i < menulist->screen_items - 1; i++)
				menulist->pixmap_pos[i] =
					menulist->pixmap_pos[i + 1];
			menulist->pixmap_pos[menulist->screen_items - 1] = tmp;
			/* draw appropriate text to the bottom pixmap */
			menu_retext_pixmap(menulist, menulist->screen_items -
					1, &menulist->items[sel - (j-1)]);
		}
	}
	/* if sel is above the visible screen */
	else if(diff < 0) {
		/* set top item */
		menulist->top_item = sel;
		/* for each time the screen shifts up, rotate the pixmaps */
		for(j = diff; j < 0; j++) {
			tmp = menulist->pixmap_pos[menulist->screen_items - 1];
			for(i = menulist->screen_items - 1; i > 0; i--)
				menulist->pixmap_pos[i] =
					menulist->pixmap_pos[i - 1];
			menulist->pixmap_pos[0] = tmp;
			/* draw appropriate text to the top pixmap */
			menu_retext_pixmap(menulist, 0,
					&menulist->items[sel - (j+1)]);
		}
	}
}
/* selection changer, for the lazy */
void menu_shift_selected(menu_st *menulist, int num)
{
	int sel;
	sel = menulist->sel + num;
	/* overboard */
	if(sel < 0 || sel > menulist->num_items - 1)
		return;
	menu_select_item(menulist, sel);
}

menu_st *menu_handle_item(menu_st *menulist, int num)
{
	item_st *item;
	/* out of bounds */
	if(num < 0 || num >= menulist->num_items) {
		Dprintf("menu_handle_item::Invalid item");
		return menulist;
	}
	item = &menulist->items[num];
	menulist->lastsel = -1;

	if(SUB_MENU_HEADER & item->op) {
		/* Destroy timer */
		menu_handle_timer(menulist, 1);
		/* create another sub-menu  */
		menulist = menu_init(menulist->menu_wid, menulist->menu_gc,
				item->text, menulist->x, menulist->y,
				menulist->w, menulist->h, menulist,
				(item_st *)item->action);
	}
	else if(ACTION_MENU & item->op) {
		/* execute the function */
		void (* fp)(void);
		fp = item->action;
		(* fp)();
		menulist->lastsel = 0;
	}
	else if(BOOLEAN_MENU & item->op) {
		/* toggle boolean; draw */
		item->sel_option = !(item->sel_option);
		if(item->setting != 0)
			ipod_set_setting(item->setting, item->sel_option);
		menu_retext_pixmap(menulist, num - menulist->top_item, item);
	}
	else if(OPTION_MENU & item->op) {
		/* rotate option; draw */
		item->sel_option = ((item->sel_option + 1) >
				(item->item_count - 1) ? 0 :
				item->sel_option + 1);
		if(item->setting != 0)
			ipod_set_setting(item->setting, item->sel_option);
		menu_retext_pixmap(menulist, num - menulist->top_item, item);
	}
	
	/* this isnt an else, so you can do (ACTION_MENU|SUB_MENU_PREV) */
	if(SUB_MENU_PREV & item->op) {
		menulist = menu_destroy(menulist);
	}
	return menulist;
}

/* removes the referenced item from the menu */
void menu_delete_item(menu_st *menulist, int num)
{
	int i, tmp;
	/* if num is off the end either way, do nothing */
	if(num > menulist->num_items - 1 || num < 0) {
		Dprintf("menu_delete_item::Invalid item\n");
		return;
	}
	if(menulist->alloc_items == 0) {
		Dprintf("menu_delete_item::Deleting from a static menu causes "
				"undefined behavior\n");
		return;
	}

	/* assume removed item is onscreen */
	tmp = menulist->pixmap_pos[num-menulist->top_item];
	for(i = 0; i < (menulist->screen_items-(num-menulist->top_item))-1;
			i++) {
		menulist->pixmap_pos[(num-menulist->top_item) + i] =
			menulist->pixmap_pos[(num-menulist->top_item) + (i+1)];
		menu_draw_item(menulist, num-menulist->top_item + i);
	}
	menulist->pixmap_pos[menulist->screen_items - 1] = tmp;
	
	/* actually remove the item */
	for(i = num; i < menulist->num_items - 1; i++)
		menulist->items[i] = menulist->items[i + 1];
	menulist->num_items--;
	/* if last item was selected, shift selected */
	if(menulist->sel == menulist->num_items)
		menu_shift_selected(menulist, -1);

	/* erase pixmaps that are off the bottom of the list */
	if(menulist->top_item + (menulist->screen_items - 1) >
			menulist->num_items - 1)
		menu_clear_pixmap(menulist, menulist->screen_items - 1);

	/* draw appropriate text to the bottom pixmap */
	else
		menu_retext_pixmap(menulist, menulist->screen_items -
				1, &menulist->items[menulist->top_item +
				(menulist->screen_items - 1)]);

	/* specify if scrollbar should draw */
	if(menulist->num_items <= menulist->screen_items)
		menulist->scrollbar = 0;

}

void menu_add_item(menu_st *menulist, char *text, void *action, int count,
		unsigned int op)
{
	if(menulist->alloc_items == 0) {
		Dprintf("Can't add items to a static menu\n");
		return;
	}
	/* allocated more space to the item list if necessary */
	if(menulist->num_items + 1 > menulist->alloc_items) {
		menulist->items = (item_st *)realloc(menulist->items, (20 +
				menulist->alloc_items) * sizeof(item_st));
		menulist->alloc_items+=20;
	}
	
	menulist->items[menulist->num_items].action = action;
	menulist->items[menulist->num_items].item_count = count;
	menulist->items[menulist->num_items].op = op;
	menulist->items[menulist->num_items].text = text;
	menulist->items[menulist->num_items].orig_pos = menulist->num_items++;

	/* specify if scrollbar should draw */
	if(menulist->num_items > menulist->screen_items)
		menulist->scrollbar = 1;
}

inline void swap(item_st a[], int i, int j)
{
	item_st t = a[i];
	a[i] = a[j];
	a[j] = t;
}
/* sorting and indexing; this one doesnt require a sentiant */
void quicksort(item_st a[], int lower, int upper)
{
	int i, m;
	item_st pivot;

	if(lower < upper) {
		swap(a, lower, (upper+lower)/2);
		pivot = a[lower];
		m = lower;
		for(i = lower + 1; i <= upper; i++)
			if(strcasecmp(a[i].text, pivot.text) < 0)
				swap(a, ++m, i);
		swap(a, lower, m);
		quicksort(a, lower, m - 1);
		quicksort(a, m + 1, upper);
	}
}

/* sorts items alphabetically and indexes them */
void menu_sort_menu(menu_st *menulist)
{
	quicksort(menulist->items, 0, menulist->num_items-1);
}

#if 0
void menu_move_item(menu_st *menulist, int sel, int shift)
{
	int i;
	for(i = shift; (shift > 0) ? (i > 0; i--) : (i < 0; i++)) {
		swap(menulist->items, sel + ,) 
	}
}
#endif

/* menu initialization, make sure to do a menu_destroy when you are finished */
menu_st *menu_init(GR_WINDOW_ID menu_wid, GR_GC_ID menu_gc, char *title, int x,
		int y, int w, int h, menu_st *parent, item_st *items)
{
	menu_st *menulist;
	int i;

	menulist = (menu_st *)malloc(sizeof(menu_st));

	/* starting with an empty slate */
	if(items == NULL) {
		menulist->items = (item_st *)malloc(20 * sizeof(item_st));
		menulist->num_items = 0;
		menulist->alloc_items = 20;
	}
	/* starting with a static menu */
	else {
		menulist->items = items;
		for(i = 0; items[i].text != 0; i++)
			items[i].orig_pos = i;
		menulist->num_items = i;
		menulist->alloc_items = 0;
	}
	
	menulist->title = title;
	menulist->sel = 0;
	menulist->init = 0;
	menulist->timer = 0;
	menulist->top_item = 0;
	menulist->scrollbar = 0;
	menulist->timer_step = 0;
	menulist->parent = parent;
	menulist->lastsel = -1;
	GrGetGCTextSize(menu_gc, "M", -1, GR_TFASCII, &menulist->width,
			&menulist->height, &menulist->base);
	/* add a 2px padding to the text */
	menulist->height += 4;

	/* determine how many items can fit on a screen */
	menulist->screen_items = (int)h/menulist->height;
	menulist->x = x;
	menulist->y = y;
	menulist->w = w;
	menulist->h = h;

	menulist->menu_wid = menu_wid; 
	/* copy the gc so we can change it */
	menulist->menu_gc = GrCopyGC(menu_gc); 

	/* initialize pixmaps */
	for(i = 0; i < menulist->screen_items; i++) {
		menulist->pixmaps[i] = GrNewPixmap(220, menulist->height, NULL);
		menulist->pixmap_pos[i] = i;
		menu_clear_pixmap(menulist, i);
	}
#if 0
	Dprintf("Init::%d items per screen at %dpx\n\tbecause %d/%d == %d\n",
			menulist->screen_items, menulist->height, menulist->h,
			menulist->height, menulist->screen_items);
#endif
	return menulist;
}

/* if you are apt enough to use this to clean-up, everyone profits */
menu_st *menu_destroy(menu_st *menulist)
{
	int i;
	menu_st *parent = menulist->parent;

	/* make sure its not a static menu we are trying to free */
	if(menulist->alloc_items != 0)
		free(menulist->items);
	if(menulist->timer)
		GrDestroyTimer(menulist->timer);
	GrDestroyGC(menulist->menu_gc);
	for(i=0; i<menulist->screen_items; i++)
		GrDestroyWindow(menulist->pixmaps[i]);
	free(menulist);

	return parent;
}

/* destroy all humans. err.. menus */
void menu_destroy_all(menu_st *menulist)
{
	menu_st *parent = menulist;
	while((parent = menu_destroy(parent)) != NULL);
}
