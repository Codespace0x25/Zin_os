ENTRY(loader)
OUTPUT_FORMAT(rlf32-i386)
OUTPUT_ARCH(i386:i386)

SECTIONS
{
	. = 0x0100000;

	.text :
	{
		*(.multiboot)
		*(.text*)
		*(.rodata)

	}


	.bss :
	{
		*(.bss)
	}

	/DISCARD/ :
	{
		*(.fini_array*)
		*(.comment)

}
