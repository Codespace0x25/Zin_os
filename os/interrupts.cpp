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
    // Function implementation to set interrupt descriptor table entry
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

    SetInterruptDescriptorTableEntry(0x20, CodeSegment, &HandleInterruptRequest0x00, 0, IDE_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x21, CodeSegment, &HandleInterruptRequest0x01, 0, IDE_INTERRUPT_GATE);

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

    struct InterruptDescriptorTablePointer
    {
        uint16_t size;
        uint32_t base;
    } __attribute__((packed));

    InterruptDescriptorTablePointer idt;
    idt.size = 256 * sizeof(GateDescriptor) - 1;
    idt.base = (uint32_t)interruptDescriptorTable;
    asm volatile("lidt %0" : : "m"(idt));
}

void InterruptMan::Activate()
{
    asm("sti");
}

uint32_t InterruptMan::handleInterrupt(uint8_t interruptNum, uint32_t esp)
{
    // Function implementation to handle interrupts
    // Add a proper return statement here
    return esp;
}

void InterruptMan::IgnoreInterruptRequest()
{
    // Function implementation to ignore interrupt requests
}

void InterruptMan::HandleInterruptRequest0x00()
{
    // Function implementation to handle interrupt request 0x00
}

void InterruptMan::HandleInterruptRequest0x01()
{
    // Function implementation to handle interrupt request 0x01
}
