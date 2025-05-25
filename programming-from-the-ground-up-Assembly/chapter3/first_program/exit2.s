#Purpose: Return the ring to modor... and return the number 3

.section .data
.section .text 
.globl _start

_start:
movl $3, %eax
movl %eax, %ebx
movl $1, %eax 

int $0x80


