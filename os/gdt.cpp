#include "hedders/gdt.h"

GlobalDescriptorTable::GlobalDescriptorTable()
    : nullSegmentselector(0, 0, 0),
      unusedSegmentselector(0, 0, 0),
      codeSegmentSelector(0, 64 * 1024 * 1024, 0x9A),
      dataSegmentSelector(0, 64 * 1024 * 1024, 0x92)
{
    uint32_t i[2] = {0, 0};
    i[0] = (uint32_t)this;
    i[1] = sizeof(GlobalDescriptorTable) << 16;

    asm volatile("lgdt (%0)" : : "r"((uint32_t)i + 2));

}

GlobalDescriptorTable::~GlobalDescriptorTable()
{
}

uint16_t GlobalDescriptorTable::DataSegmentSelector()
{
    return (uint8_t *)&dataSegmentSelector - (uint8_t *)this;
}

uint16_t GlobalDescriptorTable::CodeSegmentSelector()
{
    return (uint8_t *)&codeSegmentSelector - (uint8_t *)this;
}

GlobalDescriptorTable::SegmentDescriptor::SegmentDescriptor(uint32_t base, uint32_t limit, uint8_t type)
{
    uint8_t *target = (uint8_t *)this;

    if (limit <= 65536)
    {
        target[6] = 0x40; // 16-bit limit
    }
    else
    {
        if ((limit & 0xFFF) != 0xFFF)
        {
            limit = (limit >> 12) - 1; // Adjust limit for 4KB granularity
        }
        else
            limit = limit >> 12;

        target[6] = 0xC0; // 32-bit limit
    }

    target[0] = limit & 0xFF;                 // Low 8 bits of limit
    target[1] = (limit >> 8) & 0xFF;          // High 8 bits of limit
    target[6] |= (limit >> 16) & 0xF;         // Upper 4 bits of limit

    target[2] = base & 0xFF;                  // Low 8 bits of base
    target[3] = (base >> 8) & 0xFF;           // Middle-low 8 bits of base
    target[4] = (base >> 16) & 0xFF;          // Middle-high 8 bits of base
    target[7] = (base >> 24) & 0xFF;          // High 8 bits of base

    target[5] = type;                         // Type of the segment descriptor
}

uint32_t GlobalDescriptorTable::SegmentDescriptor::Base()
{
    uint8_t *target = (uint8_t *)this;
    uint32_t result = target[7];

    result = (result << 8) | target[4];        // Combine the 8-bit base values
    result = (result << 8) | target[3];
    result = (result << 8) | target[2];

    return result;
}

uint32_t GlobalDescriptorTable::SegmentDescriptor::Limit()
{
    uint8_t *target = (uint8_t *)this;
    uint32_t result = target[6] & 0xF;

    result = (result << 8) | target[1];        // Combine the 8-bit limit values
    result = (result << 8) | target[0];
    if ((target[6] & 0xC0) == 0xC0)
        result = (result << 12) | 0xFFF;       // Adjust limit for 4KB granularity

    return result;
}
