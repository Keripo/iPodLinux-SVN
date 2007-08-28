/* $XFree86: xc/programs/Xserver/hw/xfree86/drivers/sis/oem300.h.c,v 1.0 2001/11/30 12:12:01 eich Exp $ */
/*
 * OEM Data for 300 series
 *
 * Copyright 2002, 2003 by Thomas Winischhofer, Vienna, Austria
 *
 * If distributed as part of the linux kernel, the contents of this file
 * is entirely covered by the GPL.
 *
 * Otherwise, the following terms apply:
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the name of the copyright holder not be used in
 * advertising or publicity pertaining to distribution of the software without
 * specific, written prior permission.  The copyright holder makes no representations
 * about the suitability of this software for any purpose.  It is provided
 * "as is" without express or implied warranty.
 *
 * THE COPYRIGHT HOLDER DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
 * EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 *
 * Author: 	Thomas Winischhofer <thomas@winischhofer.net>
 *
 * Based on code by Silicon Intergrated Systems
 *
 */

const UCHAR SiS300_OEMTVDelay301[8][4] =
{
	{0x08,0x08,0x08,0x08},
	{0x08,0x08,0x08,0x08},
	{0x08,0x08,0x08,0x08},
	{0x2c,0x2c,0x2c,0x2c},
	{0x08,0x08,0x08,0x08},
	{0x08,0x08,0x08,0x08},
	{0x08,0x08,0x08,0x08},
	{0x20,0x20,0x20,0x20}
};

const UCHAR SiS300_OEMTVDelayLVDS[8][4] =
{
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20}
};

const UCHAR SiS300_OEMTVFlicker[8][4] =
{
	{0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00}
};

#if 0   /* TW: Not used */
const UCHAR SiS300_OEMLCDDelay1[12][4]={
	{0x2c,0x2c,0x2c,0x2c},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x2c,0x2c,0x2c,0x2c},
	{0x2c,0x2c,0x2c,0x2c},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x24,0x24,0x24,0x24},
	{0x24,0x24,0x24,0x24},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x24,0x24,0x24,0x24}
};
#endif

/* TW: From 630/301B BIOS */
const UCHAR SiS300_OEMLCDDelay2[64][4] =		 /* for 301/301b/302b/301LV/302LV */
{
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20}
};

/* TW: From 300/301LV BIOS */
const UCHAR SiS300_OEMLCDDelay4[12][4] =
{
	{0x2c,0x2c,0x2c,0x2c},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x2c,0x2c,0x2c,0x2c},
	{0x2c,0x2c,0x2c,0x2c},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x24,0x24,0x24,0x24},
	{0x24,0x24,0x24,0x24},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x24,0x24,0x24,0x24}
};

/* TW: From 300/301LV BIOS */
const UCHAR SiS300_OEMLCDDelay5[32][4] =
{
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
};

/* TW: Added for LVDS */
const UCHAR SiS300_OEMLCDDelay3[64][4] = {	/* For LVDS */
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x20}
};

const UCHAR SiS300_Phase1[8][6][4] =
{
    {
	{0x21,0xed,0x00,0x08},
	{0x21,0xed,0x8a,0x08},
	{0x21,0xed,0x8a,0x08},
	{0x21,0xed,0x8a,0x08},
	{0x21,0xed,0x8a,0x08},
	{0xff,0xff,0xff,0xff}
    },
    {
        {0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0xff,0xff,0xff,0xff}
    },
    {
        {0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0xff,0xff,0xff,0xff}
    },
    {
        {0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0xff,0xff,0xff,0xff}
    },
    {
        {0x21,0xed,0x00,0x08},
	{0x21,0xed,0x8a,0x08},
	{0x21,0xed,0x8a,0x08},
	{0x21,0xed,0x8a,0x08},
	{0x21,0xed,0x8a,0x08},
	{0xff,0xff,0xff,0xff}
    },
    {
        {0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0xff,0xff,0xff,0xff}
    },
    {
        {0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0xff,0xff,0xff,0xff}
    },
    {
        {0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0xff,0xff,0xff,0xff}
    }
};


const UCHAR SiS300_Phase2[8][6][4] =
{
    {
        {0x21,0xed,0x00,0x08},
	{0x21,0xed,0x8a,0x08},
	{0x21,0xed,0x8a,0x08},
	{0x21,0xed,0x8a,0x08},
	{0x21,0xed,0x8a,0x08},
	{0xff,0xff,0xff,0xff}
    },
    {
	{0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0xff,0xff,0xff,0xff}
    },
    {
        {0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0xff,0xff,0xff,0xff}
    },
    {
        {0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0xff,0xff,0xff,0xff}
    },
    {
        {0x21,0xed,0x00,0x08},
	{0x21,0xed,0x8a,0x08},
	{0x21,0xed,0x8a,0x08},
	{0x21,0xed,0x8a,0x08},
	{0x21,0xed,0x8a,0x08},
	{0xff,0xff,0xff,0xff}
    },
    {
        {0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0xff,0xff,0xff,0xff}
    },
    {
        {0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0xff,0xff,0xff,0xff}
    },
    {
        {0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0x2a,0x05,0xd3,0x00},
	{0xff,0xff,0xff,0xff}
    }
};

const UCHAR SiS300_Filter1[10][16][4] =
{
    {
	{0x00,0xf4,0x10,0x38},
	{0x00,0xf4,0x10,0x38},
	{0xeb,0x04,0x10,0x18},
	{0xf7,0x06,0x19,0x14},
	{0x00,0xf4,0x10,0x38},
	{0xeb,0x04,0x25,0x18},
	{0xeb,0x04,0x25,0x18},
	{0xeb,0x15,0x25,0xf6},
	{0xeb,0x04,0x25,0x18},
	{0xeb,0x04,0x25,0x18},
	{0xeb,0x04,0x25,0x18},
	{0xeb,0x04,0x25,0x18},
	{0xeb,0x04,0x25,0x18},
	{0xeb,0x04,0x25,0x18},
	{0xeb,0x04,0x25,0x18},
	{0xeb,0x04,0x25,0x18}
    },
    {
	{0x00,0xf4,0x10,0x38},
	{0x00,0xf4,0x10,0x38},
	{0xf1,0xf7,0x10,0x32},
	{0xf3,0x00,0x1d,0x20},
	{0x00,0xf4,0x10,0x38},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xfc,0xfb,0x14,0x2a},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32}
    },
    {
	{0x00,0xf4,0x10,0x38},
	{0x00,0xf4,0x10,0x38},
	{0xf1,0xf7,0x10,0x32},
	{0xf3,0x00,0x1d,0x20},
	{0x00,0xf4,0x10,0x38},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xfc,0xfb,0x14,0x2a},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32}
    },
    {
	{0x00,0xf4,0x10,0x38},
	{0x00,0xf4,0x10,0x38},
	{0xf1,0xf7,0x10,0x32},
	{0xf3,0x00,0x1d,0x20},
	{0x00,0xf4,0x10,0x38},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xfc,0xfb,0x14,0x2a},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32}
    },
    {
	{0x00,0xf4,0x10,0x38},
	{0x00,0xf4,0x10,0x38},
	{0xeb,0x04,0x10,0x18},
	{0xf7,0x06,0x19,0x14},
	{0x00,0xf4,0x10,0x38},
	{0xeb,0x04,0x25,0x18},
	{0xeb,0x04,0x25,0x18},
	{0xeb,0x15,0x25,0xf6},
	{0xeb,0x04,0x25,0x18},
	{0xeb,0x04,0x25,0x18},
	{0xeb,0x04,0x25,0x18},
	{0xeb,0x04,0x25,0x18},
	{0xeb,0x04,0x25,0x18},
	{0xeb,0x04,0x25,0x18},
	{0xeb,0x04,0x25,0x18},
	{0xeb,0x04,0x25,0x18}
    },
    {
	{0x00,0xf4,0x10,0x38},
	{0x00,0xf4,0x10,0x38},
	{0xf1,0xf7,0x10,0x32},
	{0xf3,0x00,0x1d,0x20},
	{0x00,0xf4,0x10,0x38},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xfc,0xfb,0x14,0x2a},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32}
    },
    {
	{0x00,0xf4,0x10,0x38},
	{0x00,0xf4,0x10,0x38},
	{0xf1,0xf7,0x10,0x32},
	{0xf3,0x00,0x1d,0x20},
	{0x00,0xf4,0x10,0x38},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xfc,0xfb,0x14,0x2a},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32}
    },
    {
	{0x00,0xf4,0x10,0x38},
	{0x00,0xf4,0x10,0x38},
	{0xf1,0xf7,0x10,0x32},
	{0xf3,0x00,0x1d,0x20},
	{0x00,0xf4,0x10,0x38},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xfc,0xfb,0x14,0x2a},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32},
	{0xf1,0xf7,0x1f,0x32}
    },
    {
	{0x00,0xf4,0x10,0x38},
	{0x00,0xf4,0x10,0x38},
	{0xeb,0x04,0x10,0x18},
	{0xf7,0x06,0x19,0x14},
	{0x00,0xf4,0x10,0x38},
	{0xeb,0x04,0x25,0x18},
	{0xeb,0x04,0x25,0x18},
	{0xeb,0x15,0x25,0xf6},
	{0xeb,0x04,0x25,0x18},
	{0xeb,0x04,0x25,0x18},
	{0xeb,0x04,0x25,0x18},
	{0xeb,0x04,0x25,0x18},
	{0xeb,0x04,0x25,0x18},
	{0xeb,0x04,0x25,0x18},
	{0xeb,0x04,0x25,0x18},
	{0xeb,0x04,0x25,0x18}
    },
    {
	{0x00,0xf4,0x10,0x38},
	{0x00,0xf4,0x10,0x38},
	{0xeb,0x04,0x10,0x18},
	{0xf7,0x06,0x19,0x14},
	{0x00,0xf4,0x10,0x38},
	{0xeb,0x04,0x25,0x18},
	{0xeb,0x04,0x25,0x18},
	{0xeb,0x15,0x25,0xf6},
	{0xeb,0x04,0x25,0x18},
	{0xeb,0x04,0x25,0x18},
	{0xeb,0x04,0x25,0x18},
	{0xeb,0x04,0x25,0x18},
	{0xeb,0x04,0x25,0x18},
	{0xeb,0x04,0x25,0x18},
	{0xeb,0x04,0x25,0x18},
	{0xeb,0x04,0x25,0x18}
    },
};

const UCHAR SiS300_Filter2[10][9][7] =
{
    {
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0x01,0x02,0xFE,0xF7,0x03,0x27,0x3C},
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0x01,0x02,0xFE,0xF7,0x03,0x27,0x3C},
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0x01,0x02,0xFE,0xF7,0x03,0x27,0x3C},
	{0x01,0x01,0xFC,0xF8,0x08,0x26,0x38},
	{0xFF,0xFF,0xFC,0x00,0x0F,0x22,0x28}
    },
    {
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0x01,0x02,0xFE,0xF7,0x03,0x27,0x3C},
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0x01,0x02,0xFE,0xF7,0x03,0x27,0x3C},
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0x01,0x02,0xFE,0xF7,0x03,0x27,0x3C},
	{0x01,0x01,0xFC,0xF8,0x08,0x26,0x38},
	{0xFF,0xFF,0xFC,0x00,0x0F,0x22,0x28}
    },
    {
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0x01,0x02,0xFE,0xF7,0x03,0x27,0x3C},
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0x01,0x02,0xFE,0xF7,0x03,0x27,0x3C},
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0x01,0x02,0xFE,0xF7,0x03,0x27,0x3C},
	{0x01,0x01,0xFC,0xF8,0x08,0x26,0x38},
	{0xFF,0xFF,0xFC,0x00,0x0F,0x22,0x28}
    },
    {
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0x01,0x02,0xFE,0xF7,0x03,0x27,0x3C},
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0x01,0x02,0xFE,0xF7,0x03,0x27,0x3C},
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0x01,0x02,0xFE,0xF7,0x03,0x27,0x3C},
	{0x01,0x01,0xFC,0xF8,0x08,0x26,0x38},
	{0xFF,0xFF,0xFC,0x00,0x0F,0x22,0x28}
    },
    {
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0x01,0x02,0xFE,0xF7,0x03,0x27,0x3C},
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0x01,0x02,0xFE,0xF7,0x03,0x27,0x3C},
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0x01,0x02,0xFE,0xF7,0x03,0x27,0x3C},
	{0x01,0x01,0xFC,0xF8,0x08,0x26,0x38},
	{0xFF,0xFF,0xFC,0x00,0x0F,0x22,0x28}
    },
    {
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0x01,0x02,0xFE,0xF7,0x03,0x27,0x3C},
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0x01,0x02,0xFE,0xF7,0x03,0x27,0x3C},
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0x01,0x02,0xFE,0xF7,0x03,0x27,0x3C},
	{0x01,0x01,0xFC,0xF8,0x08,0x26,0x38},
	{0xFF,0xFF,0xFC,0x00,0x0F,0x22,0x28}
    },
    {
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0x01,0x02,0xFE,0xF7,0x03,0x27,0x3C},
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0x01,0x02,0xFE,0xF7,0x03,0x27,0x3C},
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0x01,0x02,0xFE,0xF7,0x03,0x27,0x3C},
	{0x01,0x01,0xFC,0xF8,0x08,0x26,0x38},
	{0xFF,0xFF,0xFC,0x00,0x0F,0x22,0x28}
    },
    {
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0x01,0x02,0xFE,0xF7,0x03,0x27,0x3C},
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0x01,0x02,0xFE,0xF7,0x03,0x27,0x3C},
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0x01,0x02,0xFE,0xF7,0x03,0x27,0x3C},
	{0x01,0x01,0xFC,0xF8,0x08,0x26,0x38},
	{0xFF,0xFF,0xFC,0x00,0x0F,0x22,0x28}
    },
    {
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0x01,0x02,0xFE,0xF7,0x03,0x27,0x3C},
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0x01,0x02,0xFE,0xF7,0x03,0x27,0x3C},
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0x01,0x02,0xFE,0xF7,0x03,0x27,0x3C},
	{0x01,0x01,0xFC,0xF8,0x08,0x26,0x38},
	{0xFF,0xFF,0xFC,0x00,0x0F,0x22,0x28}
    },
    {
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0x01,0x02,0xFE,0xF7,0x03,0x27,0x3C},
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0x01,0x02,0xFE,0xF7,0x03,0x27,0x3C},
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0xFF,0x03,0x02,0xF6,0xFC,0x27,0x46},
	{0x01,0x02,0xFE,0xF7,0x03,0x27,0x3C},
	{0x01,0x01,0xFC,0xF8,0x08,0x26,0x38},
	{0xFF,0xFF,0xFC,0x00,0x0F,0x22,0x28}
    }
};

/* Custom data for Barco iQ Pro R300 */
const UCHAR barco_p1[2][9][7][3] = {
    {
	{  { 0x16, 0xcf, 0x00 },
	   { 0x18, 0x00, 0x00 },
	   { 0x1a, 0xe7, 0x00 },
	   { 0x1b, 0x26, 0x00 },
	   { 0x1c, 0xff, 0x00 },
	   { 0x1d, 0x1c, 0x00 },
	   { 0x1e, 0x19, 0x00 }
	},
	{
	   { 0x16, 0xcf, 0x00 },
	   { 0x18, 0x00, 0x00 },
	   { 0x1a, 0xe7, 0x00 },
	   { 0x1b, 0x1e, 0x00 },
	   { 0x1c, 0xff, 0x00 },
	   { 0x1d, 0x1c, 0x00 },
	   { 0x1e, 0x16, 0x00 }
	},
	{
	   { 0x16, 0xcf, 0x00 },
	   { 0x1a, 0xe7, 0x00 },
	   { 0x1b, 0x26, 0x00 },
	   { 0x1c, 0xff, 0x00 },
	   { 0x1d, 0x1c, 0x00 },
	   { 0x1e, 0x19, 0x00 },
	   {    0,    0,    0 }
	},
	{
	   {    0,    0,    0 }
	},
	{
	   { 0x16, 0xcf, 0x00 },
	   { 0x1a, 0xe7, 0x00 },
	   { 0x1b, 0x26, 0x00 },
	   { 0x1c, 0xff, 0x00 },
	   { 0x1d, 0x1c, 0x00 },
	   { 0x1e, 0x1e, 0x00 },
	   {    0,    0,    0 }
	},
	{
	   { 0x16, 0xd1, 0x00 },
	   { 0x18, 0x00, 0x00 },
	   { 0x1a, 0xe7, 0x00 },
	   { 0x1b, 0x11, 0x00 },
	   { 0x1c, 0xff, 0x00 },
	   { 0x1d, 0x1c, 0x00 },
	   { 0x1e, 0x26, 0x00 }
	},
	{
	   { 0x16, 0xd1, 0x00 },
	   { 0x1a, 0xe7, 0x00 },
	   { 0x1b, 0x26, 0x00 },
	   { 0x1c, 0xff, 0x00 },
	   { 0x1d, 0x1c, 0x00 },
	   { 0x1e, 0x30, 0x00 },
	   {    0,    0,    0 }
	},
	{
	   { 0x16, 0x00, 0x00 },
	   { 0x17, 0xa0, 0x00 },
	   { 0x1a, 0xa0, 0x00 },
	   { 0x1b, 0x2a, 0x00 },
	   { 0x1c, 0xff, 0x00 },
	   { 0x1d, 0x1c, 0x00 },
	   {    0,    0,    0 }
	},
	{
	   { 0x16, 0x00, 0x00 },
	   { 0x17, 0xaa, 0x00 },
	   { 0x1a, 0xa0, 0x00 },
	   { 0x1b, 0x2a, 0x00 },
	   { 0x1c, 0xff, 0x00 },
	   { 0x1d, 0x1c, 0x00 },
	   {    0,    0,    0 }
	}
    },
    {
	{
	   { 0x16, 0xcf, 0x00 },
	   { 0x18, 0x00, 0x00 },
	   { 0x1a, 0xe7, 0x00 },
	   { 0x1b, 0x26, 0x00 },
	   { 0x1c, 0xff, 0x00 },
	   { 0x1d, 0x1c, 0x00 },
	   { 0x1e, 0x19, 0x00 }
	},
	{
	   {    0,    0,    0 }
	},
	{
	   { 0x16, 0xcf, 0x00 },
	   { 0x18, 0x00, 0x00 },
	   { 0x1a, 0xe7, 0x00 },
	   { 0x1b, 0x26, 0x00 },
	   { 0x1c, 0xff, 0x00 },
	   { 0x1d, 0x1c, 0x00 },
	   { 0x1e, 0x19, 0x00 },
	},
	{
	   {    0,    0,    0 }
	},
	{
	   { 0x16, 0xcf, 0x00 },
	   { 0x18, 0x00, 0x00 },
	   { 0x1a, 0xe7, 0x00 },
	   { 0x1b, 0x26, 0x00 },
	   { 0x1c, 0xff, 0x00 },
	   { 0x1d, 0x1c, 0x00 },
	   { 0x1e, 0x1e, 0x00 }
	},
	{
	   { 0x16, 0xd1, 0x00 },
	   { 0x18, 0x00, 0x00 },
	   { 0x1a, 0xe6, 0x00 },
	   { 0x1b, 0x11, 0x00 },
	   { 0x1c, 0xff, 0x00 },
	   { 0x1d, 0x1c, 0x00 },
	   { 0x1e, 0x26, 0x00 }
	},
	{
	   { 0x18, 0x00, 0x00 },
	   { 0x1a, 0xe0, 0x00 },
	   { 0x1b, 0x26, 0x00 },
	   { 0x1c, 0xff, 0x00 },
	   { 0x1d, 0x1c, 0x00 },
	   { 0x1e, 0x30, 0x00 },
	   {    0,    0,    0 }
	},
	{
	   {    0,    0,    0 }
	},
	{
	   {    0,    0,    0 }
	}
    }
};






