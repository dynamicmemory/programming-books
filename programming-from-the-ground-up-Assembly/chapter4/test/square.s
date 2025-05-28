.section .text
.globl square
.type square, @function

square:
  pushl %ebp
  movl %esp, %ebp

  movl 8(%ebp), %eax   # eax = input
  imull %eax, %eax     # eax = eax * eax

  movl %ebp, %esp
  popl %ebp
  ret
