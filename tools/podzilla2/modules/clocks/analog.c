/*
 * analog clock faces
 *  
 * Copyright (C) 2006 Scott Lawrence
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <sys/time.h>
#include "pz.h"
#include "clocks.h"


/* draw an angular line for the analog clock, with a ball at the end */

static void aclock_angular_line_angle(
			ttk_surface srf, ttk_color col,
			int cx, int cy,
                        double angle,
                        int length, int circdiam, int thick  )
{
        int px, py;

        px = cx + ( length * cos( angle ));
        py = cy + ( length * sin( angle ));

        if( thick ) {
		ttk_aaline( srf, cx+1, cy   , px+1, py   , col );
		ttk_aaline( srf, cx-1, cy   , px-1, py   , col );
		ttk_aaline( srf, cx  , cy+1 , px  , py+1 , col );
		ttk_aaline( srf, cx  , cy-1 , px  , py-1 , col );
        }
	ttk_aaline( srf, cx, cy, px, py, col );

        if( circdiam ) {
		ttk_aaellipse( srf, px, py, circdiam, circdiam, col );
		ttk_fillellipse( srf, px, py, circdiam, circdiam, col );
        }
}


static void aclock_angular_line(
			ttk_surface srf, ttk_color col,
			int cx, int cy,
                        int val, int max,
                        int length, int circdiam, int thick  )
{
        double angle;

        angle = (3.14159265 * ((( (val%max) * 360 ) / max) - 90)) / 180;

	aclock_angular_line_angle( srf, col, cx, cy, angle, length,
                                circdiam, thick );
}

/*
static void aclock_angular_line_offset(
			ttk_surface srf, ttk_color col,
			int cx, int cy,
                        int val, int max, double da,
                        int length, int circdiam,
                        int thick  )
{
        double angle;

        angle = (3.14159265 * ((( (val%max) * 360.0 ) / max) - 90.0 + da))
                                        / 180.0;

        aclock_angular_line_angle( srf, col, cx, cy,
                                angle, length,
                                circdiam, thick );
}
*/

#define ARM_NORMAL (0)
#define ARM_THICK  (1)

void clock_draw_simple_analog( ttk_surface srf, clocks_globals *glob )
{
	int cx = glob->w>>1;
	int cy = glob->h>>1;
	int cd = cy-5;
	int hhd = cy>>1;
	int mhd = cy-20;
	int shd = cy-22;

	/* clock face .. do a thick AA, simulated... */
	ttk_aaellipse( srf, cx, cy, cd, cd, glob->fg );
	ttk_fillellipse( srf, cx, cy, cd, cd, glob->fg );
	ttk_fillellipse( srf, cx, cy, cd-5, cd-5, glob->bg );
	ttk_aaellipse( srf, cx, cy, cd-5, cd-5, glob->fg );
	
	/* hours */
        aclock_angular_line( srf, glob->fg, cx, cy,
				(glob->dispTime->tm_hour > 12)?
					glob->dispTime->tm_hour-12:
					glob->dispTime->tm_hour,
				12, hhd, 4, ARM_THICK );
	
	/* minutes */
        aclock_angular_line( srf, glob->fg, cx, cy,
				glob->dispTime->tm_min, 60, mhd, 
				5, ARM_THICK );

	/* seconds */
        aclock_angular_line( srf, glob->fg, cx, cy,
				glob->dispTime->tm_sec, 60, shd, 
				2, ARM_NORMAL );
}


void clock_draw_nelson_analog( ttk_surface srf, clocks_globals *glob )
{
	int cx = glob->w>>1;
	int cy = glob->h>>1;
	int ld = cy-10;
	int hhd = cy>>1;
	int mhd = cy-20;
	int shd = cy-22;
	int cd = glob->h>>3;
	int x;

	
	/* lollipops */
	for( x=0 ; x<12 ; x++ ) {
		aclock_angular_line( srf, glob->border, cx, cy,
				x, 12, ld, 8, ARM_NORMAL );
		
	}

	/* center region */
	ttk_aaellipse( srf, cx, cy, cd, cd, glob->border );
	ttk_fillellipse( srf, cx, cy, cd, cd, glob->border );
	
	/* hours */
        aclock_angular_line( srf, glob->fg, cx, cy,
				(glob->dispTime->tm_hour > 12)?
					glob->dispTime->tm_hour-12:
					glob->dispTime->tm_hour,
				12, hhd, 4, ARM_THICK );
	
	/* minutes */
        aclock_angular_line( srf, glob->fg, cx, cy,
			    glob->dispTime->tm_min, 60, mhd, 5, ARM_THICK );

	/* seconds */
        aclock_angular_line( srf, glob->fg, cx, cy,
			    glob->dispTime->tm_sec, 60, shd, 0, ARM_NORMAL );

	/* more center region */
}
