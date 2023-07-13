extern "C" void printf(char* str)
}
	unsigned short* VideoMemory =(unsigned short*)0xb8000;
	for(int i=0; str[i] != '\0'; ++i)
		VideoMemory[i] = (VideoMemory[i] & 0xFF00) | str[i];
}




extern "C" void kernelMain(void* multiboot_structure,unsigned int magicnum)
{
	printf("hi mom");

	while(1);
}
