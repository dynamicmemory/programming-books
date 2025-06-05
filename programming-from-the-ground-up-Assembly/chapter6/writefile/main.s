#.include "syscalls.s"
#.include "glob-defs.s"
# .include "lib.s"

.section .data

.equ NAME, 20

record:
  .ascii "Hacker mans\0"
  .rept 8
  .byte 0
  .endr

.equ record_size, 20

fname:
  .ascii "database.dat\0"

.section .bss
.equ buffersize, 500
.lcomm buffer, buffersize

.section .text 
.globl _start 
_start:
# Open a file 
  pushl $fname 
  pushl $0x242
  call open 
  addl $8, %esp 

  # Push the fd onto the stack 
  pushl %eax  

  # Write the record to the file 
  pushl $record 
  pushl $record_size
  call write
  addl $8, %esp  #keep the fd on the stack, elmininate record and size  

  # Wind the file pointer back to the start of the file 
  movl $19, %eax 
  popl %ebx 
  xorl %ecx, %ecx 
  xorl %edx, %edx 
  int $0x80 

  pushl %ebx
  # Read the file to a buffer 
  pushl $buffer 
  pushl $record_size 
  call read
  addl $8, %esp

  # get the size of the line to write first  
  pushl $buffer 
  call count 
  addl $4, %esp 

  # Write the buffer to the stdout 
  pushl $1
  pushl $buffer
  pushl %eax
  call write
  addl $12, %esp

  # add the record again, test to see what happens
  #pushl $record 
  #pushl $record_size
  #call write 
  #addl $8, %esp 

  movl %eax, %ebx 
  movl $1, %eax 
  int $0x80 

