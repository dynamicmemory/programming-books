.section .text 
.globl _start  

_start: 
  pushl $4
  call square 
  addl $4, %esp 

  movl %eax, %ebx
  movl $1, %eax 
  int $0x80


