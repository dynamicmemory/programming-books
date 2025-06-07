.section .data 

tmp_buffer:
  .ascii "\0\0\0\0\0\0\0\0\0\0"

.section .text 

.globl _start
_start:
  pushl $tmp_buffer 
  pushl $824 
  call integer2string

  movl $4, %eax 
  movl $1, %ebx
  movl $tmp_buffer, %ecx
  movl $10, %edx 
  int $0x80 

  movl $1, %eax 
  int $0x80 
