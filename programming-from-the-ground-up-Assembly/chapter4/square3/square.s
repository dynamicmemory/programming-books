.section .text 
.globl square 
.type square, @function 

square:
  pushl %ebp
  movl %esp, %ebp 

  movl 8(%ebp), %ebx 
  movl %ebx, %eax

  imull %ebx, %eax 

  movl %ebp, %esp 
  popl %ebp
  ret 


