/*
 *  Pod Draw
 *
 * Copyright (C) 2005 Scott Lawrence (BleuLlama)
 *
 *  Commands are:
 	PLAY	clear the screen
	CW	right or down
	CCW	left or up
	ACTN	toggle LR/UD
	|<< 	color -
	>>|	color +
	MENU	save and exit
 
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

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

#define PZ_COMPAT
#include "pz.h"

static GR_WINDOW_ID	poddraw_wid;
static GR_GC_ID		poddraw_gc;
static GR_TIMER_ID      poddraw_timer;

static int poddraw_color = 0;
static int poddraw_x = 0;
static int poddraw_y = 0;
static int updown = 0;

#define PDMIN( A, B )   (((A)<(B))?(A):(B))
#define PDMAX( A, B )   (((A)>(B))?(A):(B))

static GR_COLOR colors[] = {
	BLACK,
	GRAY,
	LTGRAY,
	WHITE,

        GR_RGB( 255,   0,   0 ),
        GR_RGB( 255, 128,   0 ),
        GR_RGB( 255, 255,   0 ),
	GR_RGB( 128, 255,   0 ),

        GR_RGB(   0, 255,   0 ),
        GR_RGB(   0, 255, 128 ),
        GR_RGB(   0, 255, 255 ),
        GR_RGB(   0, 128, 255 ),

        GR_RGB(   0,   0, 255 ),
        GR_RGB( 128,   0, 255 ),
        GR_RGB( 255,   0, 255 ),
        GR_RGB( 255,   0, 128 ),

};

static GR_COLOR * poddraw_buffer;

static void poddraw_alloc_buffer( void )
{
	poddraw_buffer = (GR_COLOR *) malloc( sizeof(GR_COLOR) *
					screen_info.cols * screen_info.rows );
}

static void poddraw_free_buffer( void )
{
	if( poddraw_buffer )
		free( poddraw_buffer );
}


static void poddraw_save( void )
{
	char buf[64];
	int x;
	int choice;
	FILE * fp;

	time_t t;
	struct tm * current_time;

	choice = DIALOG_MESSAGE_2( _("Save?"), _("Save this image?"), _("Yes"), _("No"));
	if( choice == 1 ) return;

	if( !poddraw_buffer ) return;

	t = time( NULL );
	current_time = localtime( &t );
	strftime( buf, 64, "%Y-%m-%d_%H%M.ppm", current_time );

	fp = fopen( buf, "w" );
	if( !fp ) return;

	fprintf( fp, "P3\n" );
	fprintf( fp, "#generated by poddraw/podzilla\n" );
	fprintf( fp, "%d %d 255\n", screen_info.cols, 
		    screen_info.rows - HEADER_TOPLINE );
	for( x=0 ; 
	     x< (screen_info.cols * (screen_info.rows - HEADER_TOPLINE)) ;
	     x++ )
	{
		fprintf( fp, "%d %d %d\n",
			(int)poddraw_buffer[x] & 0x000000ff,
			(int)(poddraw_buffer[x]>>8) & 0x000000ff,
			(int)(poddraw_buffer[x]>>16) & 0x000000ff );
	}

	fclose( fp );

	choice = DIALOG_MESSAGE_T( "Save", "Saved.", "Ok", 3 );
}


static void poddraw_point( GR_COLOR color, int x, int y )
{
	poddraw_buffer[x+(y*screen_info.cols)] = color;
}


static void poddraw_draw_box( GR_COLOR color, int x, int y )
{
	GrSetGCForeground( poddraw_gc, color );

	GrPoint( poddraw_wid, poddraw_gc, x,   y );
	GrPoint( poddraw_wid, poddraw_gc, x+1, y+1 );
	GrPoint( poddraw_wid, poddraw_gc, x+1, y );
	GrPoint( poddraw_wid, poddraw_gc, x,   y+1 );
}


static void poddraw_place_point( int c )
{
	GR_COLOR color = colors[ c&((screen_info.bpp==16)?0x0f:0x03) ];
	poddraw_draw_box( color, poddraw_x, poddraw_y );

	poddraw_point( color, poddraw_x,   poddraw_y );
	poddraw_point( color, poddraw_x+1, poddraw_y+1 );
	poddraw_point( color, poddraw_x+1, poddraw_y );
	poddraw_point( color, poddraw_x,   poddraw_y+1 );
}


static void poddraw_cycle_point( void )
{
	static int c = 0;
	poddraw_place_point( c++ );
}


static void poddraw_cls( void )
{
	int x;

	GrSetGCForeground( poddraw_gc, colors[poddraw_color]);
	GrFillRect( poddraw_wid, poddraw_gc, 0, 0, 
		    screen_info.cols,
		    screen_info.rows - HEADER_TOPLINE );

	for( x=0 ; 
	     x< (screen_info.cols * (screen_info.rows - HEADER_TOPLINE)) ;
	     x++ )
	{
	    poddraw_buffer[x] = colors[poddraw_color];
	}
}


static int poddraw_handle_event(GR_EVENT * event)
{
	int ret = 0;
	switch( event->type )
	{
	case( GR_EVENT_TYPE_TIMER ):
		poddraw_cycle_point();
		break;
	    
	case( GR_EVENT_TYPE_KEY_DOWN ):
		switch( event->keystroke.ch )
		{
		    case IPOD_BUTTON_ACTION: /* action */
			    // toggle lr-ud
			    updown = (updown + 1) & 0x01;
			    break;

		    case IPOD_BUTTON_PLAY: /* play/pause */
			    // clear screen
			    poddraw_cls();
			    break;

		    case IPOD_BUTTON_FORWARD: /* >>| */
			    poddraw_color = (poddraw_color +1 ) & 
				(( screen_info.bpp == 16 )?0x0f:0x03);
			    poddraw_draw_box( colors[poddraw_color], 0, 0 );
			    break;

		    case IPOD_BUTTON_REWIND: /* |<< */
			    poddraw_color = (poddraw_color -1 ) & 
				(( screen_info.bpp == 16 )?0x0f:0x03);
			    poddraw_draw_box( colors[poddraw_color], 0, 0 );
			    break;

		    case IPOD_WHEEL_ANTICLOCKWISE: /* CCW spin */
			    poddraw_place_point( poddraw_color );
			    if( updown ) poddraw_x = PDMAX( poddraw_x-2, 0 );
			    else         poddraw_y = PDMAX( poddraw_y-2, 0 );
			    break;

		    case IPOD_WHEEL_CLOCKWISE: /* CW spin */
			    poddraw_place_point( poddraw_color );
			    if( updown )
				poddraw_x = PDMIN( poddraw_x+2, 
						    screen_info.cols-2 );
			    else
				poddraw_y = PDMIN( poddraw_y+2, 
					  (screen_info.rows - 
						(HEADER_TOPLINE + 1))-2);
			break;

		    case IPOD_BUTTON_MENU:
		    case ('q'):
			    poddraw_save();
			    GrDestroyTimer( poddraw_timer );
			    pz_close_window( poddraw_wid );
			    poddraw_free_buffer();
			    ret = 1;
			    break;

		    default:
			    ret |= EVENT_UNUSED;
			    break;
		}
		break;
	}
	return ret;
}

static void poddraw_do_draw( void )
{
	pz_draw_header(_("PodDraw"));
	poddraw_cycle_point();
}

void new_poddraw_window( void )
{
	poddraw_alloc_buffer();
	poddraw_gc = pz_get_gc(1);
	GrSetGCUseBackground(poddraw_gc, GR_FALSE);
	GrSetGCForeground(poddraw_gc, BLACK);

	poddraw_wid = pz_new_window(0, HEADER_TOPLINE + 1, 
	    screen_info.cols, screen_info.rows - (HEADER_TOPLINE + 1), 
	    poddraw_do_draw, poddraw_handle_event);

	GrSelectEvents( poddraw_wid, GR_EVENT_MASK_TIMER|
	    GR_EVENT_MASK_EXPOSURE|GR_EVENT_MASK_KEY_UP|GR_EVENT_MASK_KEY_DOWN);

	poddraw_timer = GrCreateTimer( poddraw_wid, 100 );

	GrMapWindow( poddraw_wid );
	poddraw_color = 0;
	poddraw_x = screen_info.cols/2;
	poddraw_y = (screen_info.rows - (HEADER_TOPLINE + 1))/2;
	poddraw_cls();
}

PZ_SIMPLE_MOD ("poddraw", new_poddraw_window, "/Extras/Stuff/PodDraw")
