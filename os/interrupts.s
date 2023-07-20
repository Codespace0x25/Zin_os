.set IRQ_BASE, 0x20


.section .text

.extern _ZN16InterruptManager15handleInterruptEhj

.global _ZN16InterruptManager22HIgnoreInterruptRequestEv

.macro HamdInterruptRequest num
.global _ZN16InterruptManager16HandleInterruptRequest\num\()Ev:
_ZN16InterruptManager16HandleInterruptRequest\num\()Ev:
  movb $\num ,(interruptNum)
  jmp int_botton
.endm

.macro HamdInterruptRequest num
.global _ZN16InterruptManager26HandleInterruptRequest\num\()Ev:
_ZN16InterruptManager26HandleInterruptRequest\num\()Ev:
  movb $\num + IRQ_BASE ,(interruptNum)
  jmp int_botton
.endm

HamdInterruptRequest 0x00
HamdInterruptRequest 0x01



int_botton:
  pusha
  pushl %ds
  pushl %es
  pushl %fs
  pushl %gs
  
  pushl %esp
  push (interruptNum)
  call _ZN16InterruptManager15handleInterruptEhj
  #addl $5, %esp
  mov %eax, %esp
  
  
  popl %gs
  popl %fs
  popl %es
  popl %ds
  popa
  
_ZN16InterruptManager22HIgnoreInterruptRequestEv:
  
  iret

.data
  interruptNum: .byte 0
  