.include "linux.s"

.equ ST_ERROR_CODE, 8
.equ ST_ERROR_MSG, 12
.globl error_exit
error_exit:
  pushl %ebp
  movl %esp, %ebp 

  movl ST_ERROR_CODE(%ebp), %ecx
  pushl %ecx 
  call count_chars 
  popl %ecx 
  movl %eax, %edx
  movl $STDERR, %ebx 
  movl $SYS_WRITE, %eax 
  int $CALL_LINUS
 
  movl ST_ERROR_MSG(%ebp), %ecx
  pushl %ecx 
  call count_chars 
  popl %ecx 
  movl %eax, %edx
  movl $STDERR, %ebx 
  movl $SYS_WRITE, %eax 
  int $CALL_LINUS

  call write_newline 

  movl $SYS_EXIT, %eax 
  movl $1, %ebx 
  int $CALL_LINUS
 
   
   
