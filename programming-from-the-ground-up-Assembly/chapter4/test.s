.section .data

.section .text 

.globl _start 
_start:
  pushl $3
  pushl $6
  movl 4(%esp), %ebx
  movl $1, %eax
  int $0x80


