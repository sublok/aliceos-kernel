/*
	berp.c : Unrecoverable error handling.
	(C)2012-2013 Marisa Kirisame, UnSX Team.
	Part of AliceOS, the Alice Operating System.
	Released under the MIT License.
*/
#include <sys/types.h>
#include <sys/helpers.h>
#include <video/loadfnt.h>
#include <video/loadimg.h>
#include <vga/struct.h>
#include <vga/mode3h.h>
#include <vga/vgapal.h>
#include <vga/vgafont.h>
#include <printk.h>
/* panic in the style of a nokinan machine basic error response printer */
void berp( const char *message, const char *file, uint32_t line )
{
	int_disable();
	/* fall back to text mode */
	mode_3h.setmode();
	mode_3h.clear();
	mode_3h.setpal(&alicepal[0]);
	setfont(&biosfnt[0]);
	mode_3h.fbsetcursor(0,0);
	/* PANIC HARD */
	mode_3h.fbsetattr(APAL_LIGHTGREEN,APAL_BLACK,EXATTR_NOSCR);
	mode_3h.fbprintf("BERP\n\\%s [%s,%u]\n",message,file,line);
	printk("\033[0;5;31mERR INST %s,%u (%s) BERP\033[0m\n",
		file,line,message);
	/* stahp */
	khalt(EXIT_BERP);
}
