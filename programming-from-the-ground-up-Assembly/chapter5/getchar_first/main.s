.section .data

# System call numbers 
.equ SYS_OPEN, 5
.equ SYS_WRITE, 4
.equ SYS_READ, 3
.equ SYS_CLOSE, 6
.equ SYS_EXIT, 1

# Standard file descriptors 
.equ STDIN, 0
.equ STDOUT, 1
.equ STERR, 2 

# System call interupt 
.equ CALL_LINUS, 0x80


.section .bss 

# Buffer 
.equ BUFFERSIZ, 500
.lcomm BUFFER, BUFFERSIZ

.section .text 
.globl _start
_start:

  // movl $69, %esi
  movl $SYS_READ, %eax
  movl $STDIN, %ebx 
  movl $BUFFER, %ecx
  movl $BUFFERSIZ, %edx
  // movl $O_RDONLY, %ecx
  // movl $0666, %edx 
  int $CALL_LINUS

  // movl %eax, %esi # input file descriptor stored in esi 
  movl %eax, %edx # input file descriptor stored in esi 

  movl $SYS_WRITE, %eax 
  movl $STDOUT, %ebx 
  movl $BUFFER, %ecx
  // movl $BUFFERSIZ, %edx # already stored buffer size in edx above 
  // movl $O_WRONLY, %ecx 
  // movl $006, %edx 
  int $CALL_LINUS

  // movl %eax, % edi # out file descriptor stored in edi 
  movl $SYS_EXIT, %eax 
  // xorl %ebx, %ebx
  int $CALL_LINUS

