#Purpose: Factorial baby 
#Variables: 
#Input:
#Output:
#Notes: Ill fill in all these sections after 

.section .data

.section .text 

.globl _start 
_start:
  
  pushl $4
  call factorial 
  
  movl %eax, %ebx   # ebx already has the value, but just going through the motions for prac
  movl $1, %eax
  int $0x80

factorial:
  pushl %ebp 
  movl %esp, %ebp 

  subl $4, %esp

  movl 8(%ebp), %ecx
  movl %ecx, %ebx

loop:
  cmpl $1, %ecx 
  je return 

  decl %ecx 
  imul %ecx, %ebx 
  jmp loop

return:
  movl %ebx, %eax 
  movl %ebp, %esp 
  popl %ebp 
  ret 
