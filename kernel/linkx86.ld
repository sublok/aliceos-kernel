/* The linker script for AliceOS kernel */
OUTPUT_FORMAT(elf32-i386) /* This one's x86 */
ENTRY(start)
phys = 0x00100000;
SECTIONS
{
	/* Code */
	.text phys : AT(phys)
	{
		code = .;
		*(.text)
		. = ALIGN(4096);
	}
	/* All the data */
	.data : AT(phys + (data - code))
	{
		data = .;
		*(.data)
		*(.rodata)
		. = ALIGN(4096);
	}
	/* Static vars */
	.bss : AT(phys + (bss - code))
	{
		bss = .;
		*(.bss)
		. = ALIGN(4096);
	}
	/* End of kernel goes here. */
	end = .;
	/* GCC a shit */
	/DISCARD/ :
	{
		*(.comment)
		*(.eh_frame)
		*(.note.gnu.build-id)
	}
}
