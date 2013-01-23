/*
	palettes.c : Colors!
	(C)2012-2013 Marisa Kirisame, UnSX Team.
	Part of AliceOS, the Alice Operating System.
	Released under the MIT License.
*/
#include <palettes.h>

/* Alice standard 16 color palette, reduced from 8-bit to DAC's 6-bit */
Uint8 alicepal[48] =
{
	0x00,0x00,0x00,	/* black */
	0x20,0x00,0x00,	/* red */
	0x08,0x20,0x00,	/* green */
	0x28,0x10,0x04,	/* brown */
	0x00,0x08,0x16,	/* blue */
	0x0F,0x00,0x16,	/* purple */
	0x04,0x28,0x34,	/* cyan */
	0x16,0x16,0x16,	/* light gray */
	0x08,0x08,0x08,	/* dark gray */
	0x3F,0x10,0x10,	/* light red */
	0x12,0x3F,0x10,	/* light green */
	0x3F,0x38,0x0F,	/* light yellow */
	0x0C,0x20,0x3F,	/* light blue */
	0x30,0x0C,0x3F,	/* light purple */
	0x12,0x38,0x3F,	/* light cyan */
	0x3F,0x3F,0x3F,	/* white */
};