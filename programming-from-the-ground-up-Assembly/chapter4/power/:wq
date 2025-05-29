#Purpose: Program to illustrate how functions work, this program will comupte 
# the value of 2^3 + 5^2

# Everything in the main program is stored in registers, s the data section 
# doesnt have anything.

.section .data 

.section .text 
.globl _start
_start:
  pushl $3       # Pushing the second argument 
  pushl $2       # Pushing the first argument 
  call power     # calling the function 
  addl $8, %esp  # move the stack pointer back
  pushl %eax     # save the first answer before calling the next function
  
  pushl $2       
  pushl $5
  call power
  addl $8, %esp 
  popl %ebx
  addl %eax, %ebx 
  
  movl $1, %eax 
  int $0x80

#Purpose: This function is used to compute the value of a number raised to a power 
#Input: 
# First argument - the base number, 
# Second argument - the power to raise it to 
#Output: Will give the result as a return value 
#Notes: The power must be 1 or greater 
#Variables: 
# %ebx - holds the base number 
# %ecx - holds the power 
# -4(%ebp) - holds the current result 
# %eax is used for temporary storage 

.type power, @function 
power:
  pushl %ebp            # Save old base pointer 
  movl %esp, %ebp       # make stack pointer the base pointer 
  subl $4, %esp         # get room for our local storage 

  movl 8(%ebp), %ebx    # put first argument in %eax
  movl 12(%ebp), %ecx   # put second argument in %ecx 

  movl %ebx, -4(%ebp)   # Stroe current result 

power_loop_start:
  cmpl $1, %ecx         # if the power is 1, we are done 
  je end_power
  movl -4(%ebp), %eax   # move the current result into %eax 
  imull %ebx, %eax      # multiply the current result by  the base number 
  movl %eax, -4(%ebp)   # store the current result 

  decl %ecx
  jmp power_loop_start

end_power:
  movl -4(%ebp), %eax   # return value goes in %eax 
  movl %ebp, %esp       # restore the stack pointer 
  popl %ebp             # restore the base pointer 
  ret 



