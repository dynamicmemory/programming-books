#.include "syscalls.s"
#.include "glob-defs.s"
# .include "lib.s"

.section .data

fname:
  .ascii "database.dat\0"

.section .text 
.globl _start 
_start:
  pushl $fname 
  pushl $0x242
  call open 
  addl $8, %esp 

  movl %eax, %ebx 
  movl $1, %eax 
  int $0x80 

