#ifndef __GOT_N
#define __GOT_N

#include "type.h"

  class GlobalDescriptorTable
  {
    
    public:
      class SegmentDescriptor
      {
        private:
          uint16_t limit_lo;
          uint16_t base_lo;
          uint8_t base_hi;
          uint8_t type;
          uint8_t flags_limit_hi;
          uint8_t base_vhi;
        
        public:
          SegmentDescriptor(uint32_t base, uint32 limit, uint8_ type);
          uint32_t Base();
          uint32_t Limit();
      }__attribute__((packed));
    
    SegmentDescriptor nullSegmentselector;
    SegmentDescriptor unusedSegmentselector;
    SegmentDescriptor codeSegmentselector;
    SegmentDescriptor dataSegmentselector;
    
    public:
      GlobalDescriptorTable();
      -GlobalDescriptorTable();
      
      uint16_t codeSegmentselector();
      uint16_t dataSegmentselector(); 
  };



#endif
