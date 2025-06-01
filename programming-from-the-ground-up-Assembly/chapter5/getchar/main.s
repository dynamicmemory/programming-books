.section .data 

.equ SYS_READ, 3
.equ SYS_WRITE, 4
.equ SYS_EXIT, 1

.equ STDIN, 0
.equ STDOUT, 1 

.equ CALL_LINUS, 0x80

.section .bss

.equ BUFFERSIZ, 500
.lcomm BUFFER, BUFFERSIZ

.section .text 

.globl _start
_start:
  movl $SYS_READ, %eax
  movl $STDIN, %ebx
  movl $BUFFER, %ecx
  movl $BUFFERSIZ, %edx
  int $CALL_LINUS

  movl %eax, %edx 

  movl $SYS_WRITE, %eax 
  movl $STDOUT, %ebx 
  movl $BUFFER, %ecx 
  int $CALL_LINUS

  movl $SYS_EXIT, %eax 
  xorl %ebx, %ebx 
  int $CALL_LINUS
