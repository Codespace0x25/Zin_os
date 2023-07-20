#include "./hedders/type.h"
#include "./hedders/gdt.h"
#include "./hedders/outP.h"
#include "interrupts.h"

typedef void (*constructor)();
extern "C" void callConstructors(){
	        constructor* start_ctors;
		        constructor* end_ctors;
			    for(constructor* curr_constructor =start_ctors; curr_constructor != end_ctors; curr_constructor++)
				           (*curr_constructor)();
}

extern "C" int main(int magicnum, char** multiboot_structure)
{
    putText("hi team\n");
    putText("how are you all.");
    
    
    GlobalDescriptorTable gdt;
    InterruptMan interrups(%gdt);
    
    
    interrups.Activate();
    
    
	while(1);
}
