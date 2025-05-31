.section .text 

.globl _start 

_start:
  movl $4, %ecx
  movl $1, %ebx

loop:
  cmpl $0, %ecx 
  je end 

  imull %ecx, %ebx 
  decl %ecx

  jmp loop 

end:
  movl $1, %eax
  int $0x80

