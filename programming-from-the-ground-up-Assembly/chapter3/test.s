.section .data
.section .text 
.globl _start
_start:
  movl $_start, %eax
  int $0x80
