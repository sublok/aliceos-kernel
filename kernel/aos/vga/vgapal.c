/*
	vgapal.c : Colors!
	(C)2012-2013 Marisa Kirisame, UnSX Team.
	Part of AliceOS, the Alice Operating System.
	Released under the MIT License.
*/
#include <sys/types.h>
/* Alice standard 16 color palette, reduced from 8-bit to DAC's 6-bit */
uint8_t alicepal[48] =
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
/* Alice standard 256 color palette, reduced from 8-bit to DAC's 6-bit */
uint8_t alicepal256[768] =
{
	/* Base (16 colors) */
	0x00,0x00,0x00, 0x20,0x00,0x00, 0x08,0x20,0x00, 0x28,0x10,0x04,
	0x00,0x08,0x16, 0x0F,0x00,0x16, 0x04,0x28,0x34, 0x16,0x16,0x16,
	0x08,0x08,0x08, 0x3F,0x10,0x10, 0x12,0x3F,0x10, 0x3F,0x38,0x0F,
	0x0C,0x20,0x3F, 0x30,0x0C,0x3F, 0x12,0x38,0x3F, 0x3F,0x3F,0x3F,
	/* General purpose palette (64 colors) */
	0x00,0x00,0x00, 0x15,0x00,0x00, 0x2B,0x00,0x00, 0x3F,0x00,0x00,
	0x00,0x15,0x00, 0x15,0x15,0x00, 0x2B,0x15,0x00, 0x3F,0x15,0x00,
	0x00,0x2B,0x00, 0x15,0x2B,0x00, 0x2B,0x2B,0x00, 0x3F,0x2B,0x00,
	0x00,0x3F,0x00, 0x15,0x3F,0x00, 0x2B,0x3F,0x00, 0x3F,0x3F,0x00,
	0x00,0x00,0x15, 0x15,0x00,0x15, 0x2B,0x00,0x15, 0x3F,0x00,0x15,
	0x00,0x15,0x15, 0x15,0x15,0x15, 0x2B,0x15,0x15, 0x3F,0x15,0x15,
	0x00,0x2B,0x15, 0x15,0x2B,0x15, 0x2B,0x2B,0x15, 0x3F,0x2B,0x15,
	0x00,0x3F,0x15, 0x15,0x3F,0x15, 0x2B,0x3F,0x15, 0x3F,0x3F,0x15,
	0x00,0x00,0x2B, 0x15,0x00,0x2B, 0x2B,0x00,0x2B, 0x3F,0x00,0x2B,
	0x00,0x15,0x2B, 0x15,0x15,0x2B, 0x2B,0x15,0x2B, 0x3F,0x15,0x2B,
	0x00,0x2B,0x2B, 0x15,0x2B,0x2B, 0x2B,0x2B,0x2B, 0x3F,0x2B,0x2B,
	0x00,0x3F,0x2B, 0x15,0x3F,0x2B, 0x2B,0x3F,0x2B, 0x3F,0x3F,0x2B,
	0x00,0x00,0x3F, 0x15,0x00,0x3F, 0x2B,0x00,0x3F, 0x3F,0x00,0x3F,
	0x00,0x15,0x3F, 0x15,0x15,0x3F, 0x2B,0x15,0x3F, 0x3F,0x15,0x3F,
	0x00,0x2B,0x3F, 0x15,0x2B,0x3F, 0x2B,0x2B,0x3F, 0x3F,0x2B,0x3F,
	0x00,0x3F,0x3F, 0x15,0x3F,0x3F, 0x2B,0x3F,0x3F, 0x3F,0x3F,0x3F,
	/* Grayscale palette (64 colors) */
	0x00,0x00,0x00, 0x01,0x01,0x01, 0x02,0x02,0x02, 0x03,0x03,0x03,
	0x04,0x04,0x04, 0x05,0x05,0x05, 0x06,0x06,0x06, 0x07,0x07,0x07,
	0x08,0x08,0x08, 0x09,0x09,0x09, 0x0A,0x0A,0x0A, 0x0B,0x0B,0x0B,
	0x0C,0x0C,0x0C, 0x0D,0x0D,0x0D, 0x0E,0x0E,0x0E, 0x0F,0x0F,0x0F,
	0x10,0x10,0x10, 0x11,0x11,0x11, 0x12,0x12,0x12, 0x13,0x13,0x13,
	0x14,0x14,0x14, 0x15,0x15,0x15, 0x16,0x16,0x16, 0x17,0x17,0x17,
	0x18,0x18,0x18, 0x19,0x19,0x19, 0x1A,0x1A,0x1A, 0x1B,0x1B,0x1B,
	0x1C,0x1C,0x1C, 0x1D,0x1D,0x1D, 0x1E,0x1E,0x1E, 0x1F,0x1F,0x1F,
	0x20,0x20,0x20, 0x21,0x21,0x21, 0x22,0x22,0x22, 0x23,0x23,0x23,
	0x24,0x24,0x24, 0x25,0x25,0x25, 0x26,0x26,0x26, 0x27,0x27,0x27,
	0x28,0x28,0x28, 0x29,0x29,0x29, 0x2A,0x2A,0x2A, 0x2B,0x2B,0x2B,
	0x2C,0x2C,0x2C, 0x2D,0x2D,0x2D, 0x2E,0x2E,0x2E, 0x2F,0x2F,0x2F,
	0x30,0x30,0x30, 0x31,0x31,0x31, 0x32,0x32,0x32, 0x33,0x33,0x33,
	0x34,0x34,0x34, 0x35,0x35,0x35, 0x36,0x36,0x36, 0x37,0x37,0x37,
	0x38,0x38,0x38, 0x39,0x39,0x39, 0x3A,0x3A,0x3A, 0x3B,0x3B,0x3B,
	0x3C,0x3C,0x3C, 0x3D,0x3D,0x3D, 0x3E,0x3E,0x3E, 0x3F,0x3F,0x3F,
	/* Free space for user-made palette (16 colors) */
	0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F,
	0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F,
	0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F,
	0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F,
	/* Free space for user-made palette (32 colors) */
	0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F,
	0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F,
	0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F,
	0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F,
	0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F,
	0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F,
	0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F,
	0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F,
	/* Free space for user-made palette (64 colors) */
	0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F,
	0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F,
	0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F,
	0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F,
	0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F,
	0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F,
	0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F,
	0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F,
	0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F,
	0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F,
	0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F,
	0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F,
	0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F,
	0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F,
	0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F,
	0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F, 0x3F,0x3F,0x3F,
};
