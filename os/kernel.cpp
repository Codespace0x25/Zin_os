#include "./hedders/type.h"
#include "..hedders/gdt.h"

/// @brief Output a colored text into the screen.
/// @param text The string to print
/// @param color The color used (0 to 15)
extern "C" void putText(const char* text, unsigned short color)
{
	unsigned short* video_mem = (unsigned short*) 0xB8000;
	color = color << 8;
	for (
		int offset = 0;
		text[offset];
		++offset)
		*video_mem++ = color | text[offset];
}

typedef void (*constructor)();
extern "C" void callConstructors(){
	        constructor* start_ctors;
		        constructor* end_ctors;
			    for(constructor* curr_constructor =start_ctors; curr_constructor != end_ctors; curr_constructor++)
				           (*curr_constructor)();
}

extern "C" int main(int magicnum, char** multiboot_structure)
{
    putText("hi team",15);
    
    
    GlobalDescriptorTable gdt;
    
    
	while(1);
}
