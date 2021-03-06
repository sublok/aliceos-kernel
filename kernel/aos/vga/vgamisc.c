/*
	vgamisc.c : miscellaneous VGA functions.
	(C)2012-2013 Marisa Kirisame, UnSX Team.
	Part of AliceOS, the Alice Operating System.
	Released under the MIT License.
*/
#include <sys/types.h>
#include <vga/vgareg.h>
#include <sys/port.h>
/* plane switch */
void planeswitch( uint8_t p )
{
	setvgareg(VGA_GC,VGA_GC_RDMSEL,p);
	setvgareg(VGA_SEQ,VGA_SEQ_MMASK,1<<(p&3));
}
/* blank screen */
void vgablank( void )
{
	uint8_t reg = getvgareg(VGA_SEQ,VGA_SEQ_CMODE);
	setvgareg(VGA_SEQ,VGA_SEQ_RESET,0x01);
	setvgareg(VGA_SEQ,VGA_SEQ_CMODE,reg|(1<<5));
	setvgareg(VGA_SEQ,VGA_SEQ_RESET,0x03);
}
/* unblank screen */
void vgaunblank( void )
{
	uint8_t reg = getvgareg(VGA_SEQ,VGA_SEQ_CMODE);
	setvgareg(VGA_SEQ,VGA_SEQ_RESET,0x01);
	setvgareg(VGA_SEQ,VGA_SEQ_CMODE,reg&~(1<<5));
	setvgareg(VGA_SEQ,VGA_SEQ_RESET,0x03);
	setvgareg(VGA_SEQ,VGA_SEQ_CMODE,reg|(1<<5));
}
/* disable text blinking and allow all 16 colors for background */
void disableblink( void )
{
	inport_b(VGA_INSTAT1);
	outport_b(VGA_AC_I,VGA_AC_ATRM);
	uint8_t reg = inport_b(VGA_AC_R);
	inport_b(VGA_INSTAT1);
	outport_b(VGA_AC_I,VGA_AC_ATRM);
	outport_b(VGA_AC_W,reg&~(1<<3));
	outport_b(VGA_AC_I,0x20);
}
/* enable text blinking reducing background colors to 8 */
void enableblink( void )
{
	inport_b(VGA_INSTAT1);
	outport_b(VGA_AC_I,VGA_AC_ATRM);
	uint8_t reg = inport_b(VGA_AC_R);
	inport_b(VGA_INSTAT1);
	outport_b(VGA_AC_I,VGA_AC_ATRM);
	outport_b(VGA_AC_W,reg|(1<<3));
	outport_b(VGA_AC_I,0x20);
}
