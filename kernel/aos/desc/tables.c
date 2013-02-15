/*
	tables.h : definitions for descriptor tables.
	(C)2012-2013 Marisa Kirisame, UnSX Team.
	Part of AliceOS, the Alice Operating System.
	Released under the MIT License.
*/
#include <desc/tables.h>
#include <memops.h>

/* Write the actual GDT pointer */
extern void gdt_flush( Uint32 ptr );
/* Write the actual IDT pointer */
extern void idt_flush( Uint32 ptr );

/* start up GDT */
void init_gdt( void );
/* set the values of a GDT entry */
void gdt_setgate( Sint32 num, Uint32 bas, Uint32 lim, Uint8 acc, Uint8 grn );
/* start up IDT */
void init_idt( void );
/* set the values of a IDT entry */
void idt_setgate( Uint8 num, Uint32 bas, Uint16 sel, Uint8 flg );

gdt_entry_t gdt_ents[5];
gdt_ptr_t gdt_ptr;
idt_entry_t idt_ents[256];
idt_ptr_t idt_ptr;

/* Initialize descriptor tables (duh) */
void init_descriptor_tables( void )
{
	/* global descriptor table */
	init_gdt();
	/* interrupt descriptor table */
	init_idt();
}

/* start up GDT */
void init_gdt( void )
{
	gdt_ptr.limit = (sizeof(gdt_entry_t)*5)-1;
	gdt_ptr.base = (Uint32)&gdt_ents;
	
	/* segments (null, code, data, user mode code, user mode data) */
	gdt_setgate(0,0,0x00000000,0x00,0x00);
	gdt_setgate(1,0,0xFFFFFFFF,0x9A,0xCF);
	gdt_setgate(2,0,0xFFFFFFFF,0x92,0xCF);
	gdt_setgate(3,0,0xFFFFFFFF,0xFA,0xCF);
	gdt_setgate(4,0,0xFFFFFFFF,0xF2,0xCF);
	/* flush~ */
	gdt_flush((Uint32)&gdt_ptr);
}

/* set the values of a GDT entry */
void gdt_setgate( Sint32 num, Uint32 bas, Uint32 lim, Uint8 acc, Uint8 grn )
{
	gdt_ents[num].base_l = (bas&0xFFFF);
	gdt_ents[num].base_m = (bas>>16)&0xFF;
	gdt_ents[num].base_h = (bas>>24)&0xFF;
	gdt_ents[num].limit_l = (lim&0xFFFF);
	gdt_ents[num].granularity = ((lim>>16)&0x0F)|(grn&0xF0);
	gdt_ents[num].access = acc;
}

/* start up IDT */
void init_idt( void )
{
	idt_ptr.limit = sizeof(idt_entry_t)*256-1;
	idt_ptr.base = (Uint32)&idt_ents;
	
	/* we have to zero everything out */
	memset((Uint8*)&idt_ents[0],0,sizeof(idt_entry_t)*256);
	/* lots of stuff */
	idt_setgate(0,(Uint32)isr0,0x08,0x8E);
	idt_setgate(1,(Uint32)isr1,0x08,0x8E);
	idt_setgate(2,(Uint32)isr2,0x08,0x8E);
	idt_setgate(3,(Uint32)isr3,0x08,0x8E);
	idt_setgate(4,(Uint32)isr4,0x08,0x8E);
	idt_setgate(5,(Uint32)isr5,0x08,0x8E);
	idt_setgate(6,(Uint32)isr6,0x08,0x8E);
	idt_setgate(7,(Uint32)isr7,0x08,0x8E);
	idt_setgate(8,(Uint32)isr8,0x08,0x8E);
	idt_setgate(9,(Uint32)isr9,0x08,0x8E);
	idt_setgate(10,(Uint32)isr10,0x08,0x8E);
	idt_setgate(11,(Uint32)isr11,0x08,0x8E);
	idt_setgate(12,(Uint32)isr12,0x08,0x8E);
	idt_setgate(13,(Uint32)isr13,0x08,0x8E);
	idt_setgate(14,(Uint32)isr14,0x08,0x8E);
	idt_setgate(15,(Uint32)isr15,0x08,0x8E);
	idt_setgate(16,(Uint32)isr16,0x08,0x8E);
	idt_setgate(17,(Uint32)isr17,0x08,0x8E);
	idt_setgate(18,(Uint32)isr18,0x08,0x8E);
	idt_setgate(19,(Uint32)isr19,0x08,0x8E);
	idt_setgate(20,(Uint32)isr20,0x08,0x8E);
	idt_setgate(21,(Uint32)isr21,0x08,0x8E);
	idt_setgate(22,(Uint32)isr22,0x08,0x8E);
	idt_setgate(23,(Uint32)isr23,0x08,0x8E);
	idt_setgate(24,(Uint32)isr24,0x08,0x8E);
	idt_setgate(25,(Uint32)isr25,0x08,0x8E);
	idt_setgate(26,(Uint32)isr26,0x08,0x8E);
	idt_setgate(27,(Uint32)isr27,0x08,0x8E);
	idt_setgate(28,(Uint32)isr28,0x08,0x8E);
	idt_setgate(29,(Uint32)isr29,0x08,0x8E);
	idt_setgate(30,(Uint32)isr30,0x08,0x8E);
	idt_setgate(31,(Uint32)isr31,0x08,0x8E);
	/* flush~ */
	idt_flush((Uint32)&idt_ptr);
}

/* set the values of a IDT entry */
void idt_setgate( Uint8 num, Uint32 bas, Uint16 sel, Uint8 flg )
{
	idt_ents[num].base_l = bas&0xFFFF;
	idt_ents[num].base_h = (bas>>16)&0xFFFF;
	idt_ents[num].sel = sel;
	idt_ents[num].zero = 0;
	idt_ents[num].flags = flg/*|0x60*/; /* <- not yet */
}
