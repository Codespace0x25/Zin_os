#ifndef __PORT_H
#define __PORT_H

#include "type.h"

class Port
{
protected:
    uint16_t portnum;
    Port(uint16_t portnum);
    ~Port();
};

class Port8Bit : public Port
{
public:
    Port8Bit(uint16_t portnum);
    ~Port8Bit();
    virtual void Write(uint8_t data) override;
    virtual uint8_t Read() override;
};

class Port8BitSlow : public Port8Bit
{
public:
    Port8BitSlow(uint16_t portnum);
    ~Port8BitSlow();
    virtual void Write(uint8_t data) override;
};

class Port16Bit : public Port
{
public:
    Port16Bit(uint16_t portnum);
    ~Port16Bit();
    virtual void Write(uint16_t data) override;
    virtual uint16_t Read() override;
};

class Port32Bit : public Port
{
public:
    Port32Bit(uint16_t portnum);
    ~Port32Bit();
    virtual void Write(uint32_t data) override;
    virtual uint32_t Read() override;
};

#endif
