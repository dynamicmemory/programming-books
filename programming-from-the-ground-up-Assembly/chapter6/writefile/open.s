.section .data

.equ parameter_one, 12
.equ parameter_two, 8
#word:
#  .ascii "Hello assembly\n\0"

.section .text 
.globl open 
// .type open, @function   // not needed as this is a separate file with glob function 
open:
  pushl %ebp 
  movl %esp, %ebp

  # open a file
  # parameter one must be file name
  # paremeter two is how you want the file opened, write, read, append, trunc? 
  movl $5, %eax
  movl parameter_one(%ebp), %ebx 
  movl parameter_two(%ebp), %ecx 
  movl $0666, %edx
  int $0x80
 
  # Write to that file, as a test for now to make sure the file is opening as a fn
  #movl %eax, %edx
  #movl $4, %eax 
  #movl %edx, %ebx
  #movl $word, %ecx 
  #movl $16, %edx 
  #int $0x80

  movl %ebp, %esp 
  popl %ebp 
  ret
