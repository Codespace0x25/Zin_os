#ifndef __INTERRUPTS_H
#define __INTERRUPTS_H

#include "port.h"
#include "type.h"
#include "gdt.h"

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
      
      static GateDescriptor interruptDescriptorTable(256);
      
      static InterruptDescriptorTablePointer
      {
        unit16_t size;
        uint32_t base;
      } __attribute__((packed));
      
      
      static void SetInterruptDescriptorTableEntry(
        uint8_t interruptNum,
        uint16_t gdt_codeSegmentorOffset,
        void (*handle)(),
        uint8_t DescriptorPrivilegeLevel,
        uint_r DescriptorType
      );
      
      port8BitSlow picMasterCommand;
      port8BitSlow picMasterData;
      port8BitSlow picSlaveCommand;
      port8BitSlow picSlaveData;
    
    public:
      
      InterruptMan(GlobalDescriptorTable* gdt);
      ~InterruptMan();
      
      void Activate();
      
      static uint32_t handleInterrupt(uint8_t interruptNum, uint32_t esp);
      static void IgnoreInterruptRequest();
      static void HamdInterruptRequest0x00();
      static void HamdInterruptRequest0x01();
  };
  
  
  

#enddif