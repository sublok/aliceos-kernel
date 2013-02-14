/*
	struct.h : Struct-based operation with graphic modes (should be more comfortable).
	(C)2012-2013 Marisa Kirisame, UnSX Team.
	Part of AliceOS, the Alice Operating System.
	Released under the MIT License.
*/
#ifndef VGASTRUCT_H
#define VGASTRUCT_H
#include <sys/types.h>
#include <video/loadimg.h>
#include <video/loadfnt.h>

/* memory access layout for modes */
#define LAYOUT_LINEAR  0
#define LAYOUT_PLANAR  1
#define LAYOUT_TEXT    2
/* color depths for modes */
#define DEPTH_2COLOR   0
#define DEPTH_4COLOR   1
#define DEPTH_16COLOR  2
#define DEPTH_256COLOR 3
/* extended attributes for text drawing */
#define EXATTR_MASKED  1 /* Zero brightness pixels of font (and background) are transparent when drawing (NOTE: Will break cursor drawing) */
#define EXATTR_HFLIP   2 /* Mirror characters horizontally */
#define EXATTR_VFLIP   4 /* Mirror characters vertically */
#define EXATTR_RCW90   8 /* Rotate 90 degrees clockwise */
#define EXATTR_RCCW90 16 /* Rotate 90 degrees counter-clockwise */
#define EXATTR_NOSCR  32 /* Character printing will never cause scrolling (NOTE: if cursor goes offscreen, no more characters will be drawn) */
#define EXATTR_REVBG  64 /* Characters will be drawn by inverting the background colors where their glyphs have a brightness above zero */
#define EXATTR_NODW  128 /* Don't draw any characters, just the background */

/* struct for video mode */
typedef struct
{
	Uint16 id;	/* identificative number */
	char name[256];	/* identificative name */
	Uint16 w, h;	/* resolution */
	Uint8 layout;	/* memory access layout (linear or planar) */
	Uint8 depth;	/* number of colors */
	Uint8 *mem;	/* pointer to framebuffer memory */
	/* mode setting */
	void (*setmode)( void );
	/* palette setting */
	void (*setpal)( Uint8* pal );
	void (*getpal)( Uint8* pal );
	/* font setting */
	void (*setfont)( fnt_t* fnt );
	fnt_t* (*getfont)( void );
	/* clear screen */
	void (*clear)( void );
	/* scrolling */
	void (*hscroll)( Sint32 offset );
	void (*vscroll)( Sint32 offset );
	/* pixel drawing functions */
	void (*putpixel)( Uint16 x, Uint16 y, Uint8 c );
	Uint8 (*getpixel)( Uint16 x, Uint16 y );
	/* primitive drawing functions (rect, line, bitmap, char, etc.) */
	void (*drawrect)( Uint16 x, Uint16 y, Uint16 w, Uint16 h, Uint8 c );
	void (*drawhline)( Uint16 x, Uint16 y, Uint16 l, Uint8 c );
	void (*drawvline)( Uint16 x, Uint16 y, Uint16 l, Uint8 c );
	void (*drawimg)( img_t *img, Uint16 x, Uint16 y, Uint16 ox, Uint16 oy, Uint16 w, Uint16 h, Uint16 palshift );
	void (*drawchar)( Uint16 x, Uint16 y, char c );
	void (*drawwchar)( Uint16 x, Uint16 y, wchar c );
	void (*drawstring)( Uint16 x, Uint16 y, char *s );
	void (*drawwstring)( Uint16 x, Uint16 y, wchar *s );
	/* framebuffer (console) management */
	void (*fbgetres)( Uint16 *cols, Uint16 *rows );
	void (*fbgetcursor)( Sint32 *col, Sint32 *row );
	void (*fbsetcursor)( Sint32 col, Sint32 row );
	void (*fbmovecursor)( Sint32 cols, Sint32 rows );
	void (*fbcursorvis)( Uint8 on );
	void (*fbputc)( char c );
	void (*fbwputc)( wchar c );
	void (*fbputs)( char *s );
	void (*fbwputs)( wchar *s );
	void (*fbprintf)( char *s, ... );
	void (*fbwprintf)( wchar *s, ... );
	void (*fbsetattr)( Uint8 fg, Uint8 bg, Uint8 ex );
	void (*fbgetattr)( Uint8 *fg, Uint8 *bg, Uint8 *ex );

} vga_mode_t;

#endif