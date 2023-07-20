#ifndef __INTERRUPTS_H
#define __INTERRUPTS_H

#include "port.h"
#include "type.h"
#include "gdt.h"
#include "outP.h" // Include outP.h instead of stdio.h

class InterruptMan
{
protected:
    struct GateDescriptor
    {
        uint16_t handlerAddressLowBits;
        uint16_t gdt_codeSegmentSelector;
        uint8_t reserved;
        uint8_t access;
        uint16_t handlerAddressHighBits;
    } __attribute__((packed));

    static GateDescriptor interruptDescriptorTable[256]; // Move the array definition here

    struct InterruptDescriptorTablePointer // Add struct keyword before the name
    {
        uint16_t size;
        uint32_t base;
    } __attribute__((packed));

    // ... rest of the class definition ...
    // Please make sure the member functions and variables are correctly defined.

public:
    InterruptMan(GlobalDescriptorTable* gdt);
    ~InterruptMan();

    // ... rest of the class definition ...

};

#endif // __INTERRUPTS_H
