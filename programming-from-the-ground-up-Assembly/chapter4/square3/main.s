.section .text 
.globl _start
_start:
  pushl $5
  call square
  subl $4, %esp

  movl %eax, %ebx
  movl $1, %eax
  int $0x80

