.include "linux.s"
.include "record-def.s"

#Purpose: This function writes a recor to the given file descriptor 
#Input: The file descriptor and a buffer 
#Output : This function produces a status code 

#Stack Local variables 
.equ ST_WRITE_BUFFER, 8
.equ ST_FILEDES, 12 

.section .text 

.global write
.type write, @function 
write:
  pushl %ebp 
  movl %esp, %ebp

  pushl %ebx
  movl $SYS_WRITE, %eax 
  movl ST_FILEDES(%ebp), %ebx 
  movl ST_WRITE_BUFFER(%ebp), %ecx
  movl $RECORD_SIZE, %edx
  int $CALL_LINUS 

# Note - %eax has the return value, which we will give back to our calling program 

  popl %ebx 

  movl %ebp, %esp 
  popl %ebp 
  ret 


