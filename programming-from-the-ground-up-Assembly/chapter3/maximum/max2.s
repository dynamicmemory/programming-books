#Purpose:
#Variables:
#Registers:

.section .data
list:
  .long 1,2,3,69,233,9,4

.section .text 

.globl _start
_start:

movl $0, %ecx
movl list(, %ecx, 4), %esi
movl %esi, %edi

start_the_loop:
  incl %ecx 
  movl list(, %ecx, 4), %esi 
  cmpl $255, %esi 
  je we_end_loops_here

  cmpl %esi, %edi 
  jge start_the_loop 
  movl %esi, %edi 
  jmp start_the_loop 

we_end_loops_here:
  movl $1, %eax
  movl %edi, %ebx
  int $0x80
