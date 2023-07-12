GPPPARMS = -m32
ASPARMS = —32
objects  = loader.o kernle.o
LDPARMS = melf_i386

%.: %.cpp
	g++$(GPPPARMS) -o $@ -c $<

%.o: %.s
	as $(ASPARMS) -o $@ $<
myKernle.bin: lenker.ld $(objects)
	ld $(LDPARMS) -T $< -o $@ $(objects)
install: myKernle.bin
	sudo cp $< /boot/myKernle.bim

