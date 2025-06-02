.include "record-def.s"
.include "linux.s"

#Purpose: This function reads a record from the file descriptor 
#Input: The file descriptor and a buffer 
#output: Thie function writes the data to the buffer and returns a status code.

#Stack local variables 
.equ ST_READ_BUFFER, 8
.equ ST_FILEDES, 12 

.section .text 

.globl read 
.type read, @function 
read: 
  pushl %ebp
  movl %esp, %ebp 

  pushl %ebx 
  movl ST_FILEDES(%ebp), %ebx 
  movl ST_READ_BUFFER(%ebp), %ecx
  movl $RECORD_SIZE, %edx 
  movl $SYS_READ, %eax 
  int $CALL_LINUS 

  # Note - %eax has the return value, which we will give back to our calling prog 

  popl %ebx

  movl %ebp, %esp 
  popl %ebp 
  ret 

