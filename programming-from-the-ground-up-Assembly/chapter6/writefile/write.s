.section .data 

.equ parameter1, 16
.equ parameter2, 12
.equ parameter3, 8

.section .text 

.globl write
write:
  pushl %ebp 
  movl %esp, %ebp 

  movl $4, %eax 
  movl parameter1(%ebp), %ebx
  movl parameter2(%ebp), %ecx
  movl parameter3(%ebp), %edx
  int $0x80

  movl %ebp, %esp 
  popl %ebp 
  ret 

