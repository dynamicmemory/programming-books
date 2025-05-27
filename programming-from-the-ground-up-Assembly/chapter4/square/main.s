#Purpose: We out here today, to square numbers 
#Input:
# First argument: the number to square 
# Second argument: the square, ie 2 
#Ouput: The first numbered square 
#Notes: No negative numbers I guess? squares cant be negative anyway 

.section .data 
.section .text 
.globl _start
_start:
  
  pushl $10
  pushl $2
  call square
  addl $8, %esp 

  #popl %eax 
  movl %ecx, %ebx
  movl $1, %eax
  int $0x80

square:
  pushl %ebp
  movl %esp, %ebp 
  
  subl $4, %esp

  movl 12(%ebp), %edi 
  movl 12(%ebp), %ecx

  imull %edi, %ecx 
  
  movl %ecx, %eax  # Move return value into eax 
  movl %ebp, %esp  # Fix the stack pointer 
  popl %ebp        # Get original base pointer val back 
  ret



