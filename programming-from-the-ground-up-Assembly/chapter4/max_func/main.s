.section .data
list: 
  .long 4,7,6,8,69,33,2,55

.section .text 

.globl _start
_start:
  movl $list, %ecx
  movl (%ecx), %eax
  movl %eax, %ebx

  movl $list, %esi
  addl $32, %esi 

loop:
  addl $4, %ecx 
  cmpl %ecx, %esi 
  je end
  
  movl (%ecx), %eax 
  cmpl %eax, %ebx 
  jge loop 
  movl %eax, %ebx 
  jmp loop

end:
  movl $1, %eax
  int $0x80
