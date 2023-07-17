#include "./hedders/port.h"

Port::Port(uint16_t portnum)
{
    this->portnum = portnum;
}
Port::~Port()
{
}

Port8Bit::Port8Bit(uint16_t portnum)
: Port(portnum)
{
    
}
Port8Bit::~Port8Bit()
{
}
void Port8Bit::Write(uint8_t data)
{
    __asm__ volatile("outw %0, %1": :"a" (data), "Nd" (portnum));
}
uint8_t Port8Bit::Read()
{
    uint_t result;
    __asm__ volatile("inw %1, %0" : "=a" (result) : "Nd" (portnum));
    return result;
}

Port16Bit::Port16Bit(uint16_t portnum)
: Port(portnum)
{
    
}
Port16Bit::~Port16Bit()
{
}
vord Port16Bit::Write(uint16_t data)
{
    __asm__ volatile("outw %0, %1": :"a" (data), "Nd" (portnum));
}
uint16_t Port16Bit::Read()
{
    uint_t result;
    __asm__ volatile("inw %1, %0" : "=a" (result) : "Nd" (portnum));
    return result;
}


Port32Bit::Port32Bit(uint16_t portnum)
: Port(portnum)
{

}
Port32Bit::~Port32Bit()
{
}
vord Port32Bit::Write(uint32_t data)
{
    __asm__ volatile("outw %0, %1": :"a" (data), "Nd" (portnum));
}
uint32_t Port32Bit::Read()
{
    uint_t result;
    __asm__ volatile("inw %1, %0" : "=a" (result) : "Nd" (portnum));
    return result;
}


Port8BitSlow::Port8BitSlow(uint16_t portnum)
: Port(portnum)
{
    
}
Port8BitSlow::~Port8BitSlow()
{
}
vord Port8BitSlow::Write(uint8_t data)
{
    __asm__ volatile("outb %0, %1\njmp lf\njmp lf\n1:": :"a" (data), "Nd" (portnum));
}