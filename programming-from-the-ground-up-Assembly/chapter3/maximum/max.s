#Purpose:
#Variables:
#Registers:

.section .data
list:
 .long 1,2,69,6,40,200,3

.section .text 

.globl _start
_start:

movl $7, %ecx
movl $1, %edi 
movl $0, %esi
movl list(,%esi,4), %eax
movl %eax, %ebx 

loop:
  cmpl $0, %ecx 
  je end 
  subl $1, %ecx
  incl %esi
  movl list(,%esi,4), %eax 
  cmpl %eax, %ebx 
  jge loop 

  movl %eax, %ebx 
  jmp loop 

end:
  movl $1, %eax
  int $0x80
