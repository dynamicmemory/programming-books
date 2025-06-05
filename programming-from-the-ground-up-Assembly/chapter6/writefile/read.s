.section .data 

.equ parameter_one, 16
.equ parameter_two, 12 
.equ parameter_three, 8

.section .text 

.globl read 
read:
  pushl %ebp
  movl %esp, %ebp

  movl $3, %eax
  movl parameter_one(%ebp), %ebx
  movl parameter_two(%ebp), %ecx 
  movl parameter_three(%ebp), %edx
  int $0x80
  
  movl %ebp, %esp 
  popl %ebp 
  ret 
