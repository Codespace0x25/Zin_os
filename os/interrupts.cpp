#include "./hedders/interrupts.h"
#include "./hedders/outP.h"


InterruptMan::GateDescriptor InterruptMan::interruptDescriptorTable[256];

void InterruptMan::SetInterruptDescriptorTableEntry(
    uint8_t interruptNum,
    uint16_t gdt_codeSegmentorOffset,
    void (*handler)(),
    uint8_t DescriptorPrivilegeLevel,
    uint8_t DescriptorType
)
{
    const uint8_t IDT_DESC_PRESENT = 0x80;

    interruptDescriptorTable[interruptNum].handlerAddressLowBits = (uint32_t)handler & 0xFFFF;
    interruptDescriptorTable[interruptNum].handlerAddressHighBits = ((uint32_t)handler >> 16) & 0xFFFF;
    interruptDescriptorTable[interruptNum].gdt_codeSegmentSelector = gdt_codeSegmentorOffset;
    interruptDescriptorTable[interruptNum].access = IDT_DESC_PRESENT | DescriptorType | ((DescriptorPrivilegeLevel & 3) << 5);
    interruptDescriptorTable[interruptNum].reserved = 0;
}

InterruptMan::InterruptMan(GlobalDescriptorTable* gdt)
    : picMasterCommand(0x20),
      picMasterData(0x21),
      picSlaveCommand(0xA0),
      picSlaveData(0xA1)
{
    uint16_t CodeSegment = gdt->CodeSegmentSelector();
    const uint8_t IDE_INTERRUPT_GATE = 0xE;

    for (uint16_t i = 0; i < 256; i++)
        SetInterruptDescriptorTableEntry(i, CodeSegment, &IgnoreInterruptRequest, 0, IDE_INTERRUPT_GATE);

    SetInterruptDescriptorTableEntry(0x20, CodeSegment, &HamdInterruptRequest0x00, 0, IDE_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x21, CodeSegment, &HamdInterruptRequest0x01, 0, IDE_INTERRUPT_GATE);

    picMasterCommand.Write(0x11);
    picSlaveCommand.Write(0x11);

    picMasterData.Write(0x20);
    picSlaveData.Write(0x28);

    picMasterData.Write(0x04);
    picSlaveData.Write(0x02);

    picMasterData.Write(0x01);
    picSlaveData.Write(0x01);

    picMasterData.Write(0x00);
    picSlaveData.Write(0x00);

    InterruptDescriptorTablePointer idt;
    idt.size = 256 * sizeof(GateDescriptor) - 1;
    idt.base = (uint32_t)interruptDescriptorTable;
    asm volatile("lidt %0" : : "m"(idt));
}

InterruptMan::~InterruptMan()
{
}

void InterruptMan::Activate()
{
    asm("sti");
}

uint32_t InterruptMan::handleInterrupt(uint8_t interruptNum, uint32_t esp)
{
    // Your code to handle the interrupt goes here
    putText("Interrupt\n");
    return esp;
}

void InterruptMan::IgnoreInterruptRequest()
{
}

void InterruptMan::HamdInterruptRequest0x00()
{
}

void InterruptMan::HamdInterruptRequest0x01()
{
}
