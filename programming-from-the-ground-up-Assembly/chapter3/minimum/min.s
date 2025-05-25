# Purpose: Find the minimum value in a list of numbers

# Variables: data_list - the list of values 

# Registers: 
# %eax to hold current element
# %ebx to hold minimum
# %edi to hold index to next element in list

.section .data 

data_items: 
  .long 4,7,44,99,8,7,33,25,78,65,55,12,90,0

.section .text 

.globl _start
_start:

movl $0, %edi
movl data_items(,%edi,4), %eax 
movl %eax, %ebx 

start_loop:
  incl %edi 
  movl data_items(,%edi,4), %eax 
  cmpl $0, %eax
  je loop_exit 
  cmpl %ebx, %eax 
  jge start_loop

  movl %eax, %ebx 
  jmp start_loop 

loop_exit:
  movl $1, %eax 
  int $0x80

