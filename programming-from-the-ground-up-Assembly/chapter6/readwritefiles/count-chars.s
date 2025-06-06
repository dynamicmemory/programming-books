# Purpose: Count the characters until a null byte is reached.
# Input: The address of the character string 
# Output: Returns the count in %eax 
# Process:
#  Registers used:
#    %ecx - character  count 
#    %al - current character 
#    %edx - current character address 

.type .count_chars, @function
.globl count_chars 

# This is where our one parameter is on the stack 
.equ ST_STRING_START_ADDRESS, 8

count_chars:
  pushl %ebp
  movl %esp, %ebp 

  movl $0, %ecx     # Counter starts at zero 
  movl ST_STRING_START_ADDRESS(%ebp), %edx 

count_loop_begin: 
  movb (%edx), %al    # Grab the current character 
  cmpb $0, %al        # Is this null?

  je count_loop_end   
  
  incl %ecx  
  incl %edx  

  jmp count_loop_begin

count_loop_end:
  movl %ecx, %eax
  popl %ebp 
  ret 


