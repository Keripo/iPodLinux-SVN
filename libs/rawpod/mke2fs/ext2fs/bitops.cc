/*
 * bitops.c --- Bitmap frobbing code.  See bitops.h for the inlined
 * 	routines.
 * 
 * Copyright (C) 1993, 1994, 1995, 1996 Theodore Ts'o.
 *
 * %Begin-Header%
 * This file may be redistributed under the terms of the GNU Public
 * License.
 * %End-Header%
 */

#include <stdio.h>

#include "ext2.h"
#include "ext2fs.h"

/*
 * For the benefit of those who are trying to port Linux to another
 * architecture, here are some C-language equivalents.  You should
 * recode these in the native assmebly language, if at all possible.
 *
 * C language equivalents written by Theodore Ts'o, 9/26/92.
 * Modified by Pete A. Zaitcev 7/14/95 to be portable to big endian
 * systems, as well as non-32 bit systems.
 */

int ext2fs_set_bit(int nr,void * addr)
{
	int		mask, retval;
	unsigned char	*ADDR = (unsigned char *) addr;

	ADDR += nr >> 3;
	mask = 1 << (nr & 0x07);
	retval = (mask & *ADDR) != 0;
	*ADDR |= mask;
	return retval;
}

int ext2fs_clear_bit(int nr, void * addr)
{
	int		mask, retval;
	unsigned char	*ADDR = (unsigned char *) addr;

	ADDR += nr >> 3;
	mask = 1 << (nr & 0x07);
	retval = (mask & *ADDR) != 0;
	*ADDR &= ~mask;
	return retval;
}

int ext2fs_test_bit(int nr, const void * addr)
{
	int			mask;
	const unsigned char	*ADDR = (const unsigned char *) addr;

	ADDR += nr >> 3;
	mask = 1 << (nr & 0x07);
	return ((mask & *ADDR) != 0);
}

void ext2fs_warn_bitmap(errcode_t errcode, unsigned long arg,
			const char *description)
{
#ifndef OMIT_COM_ERR
	if (description)
		com_err(0, errcode, "#%lu for %s", arg, description);
	else
		com_err(0, errcode, "#%lu", arg);
#endif
}

void ext2fs_warn_bitmap2(ext2fs_generic_bitmap bitmap,
			    int code, unsigned long arg)
{
#ifndef OMIT_COM_ERR
	if (bitmap->description)
		com_err(0, bitmap->base_error_code+code,
			"#%lu for %s", arg, bitmap->description);
	else
		com_err(0, bitmap->base_error_code + code, "#%lu", arg);
#endif
}

