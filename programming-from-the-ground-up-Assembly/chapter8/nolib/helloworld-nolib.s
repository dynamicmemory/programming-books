#Purpose: Writes the words hello world and then exits

.section .data 

.helloworld:
  .ascii "Hello Assembly\n"

.null:

.equ stringlen, .null - .helloworld

.section .text 
 
.globl _start
_start:
  movl $4, %eax
  movl $1, %ebx
  movl $.helloworld, %ecx
  movl $stringlen, %edx
  int $0x80

  movl $1, %eax 
  int $0x80 

