#include <cstdio>

/// @brief Output a colored text into the screen.
/// @param text The string to print
/// @param color The color used (0 to 15)
extern "C" void putText(unsigned char* text, unsigned short color)
{
	unsigned short* video_mem = (unsigned short*) 0xB8000;
	color = color << 8;
	for (
		int offset = 0;
		text[offset];
		++offset)
		*video_mem++ = color | text[offset];
}

extern "C" void kernelMain(void* multiboot_structure, unsigned int magicnum)
{
	printf("hi mom");
	while(1);
}
