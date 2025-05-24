#Purpose: This program finds the maximum number of a set of data items.

#Variables: The registers have the following uses:
# %edi - Holds the index of the data item being examined 
# %ebx - Largest data item found 
# %eax - Current data item 

# The following memory locations are used:
# data_items - contains the item data. A 0 is used to terminate the data 

.section .data 

data_items:
.long 2,69,33,222,40,60,90,77,21,21,22,88,0 # The list yo,

.section .text

.globl _start
_start:
movl $0, %edi                    # move 0 into the index register 
movl data_items(,%edi,4), %eax   # load the first byte of data 
movl %eax, %ebx                  # Since this is the first item, its the biggest 

start_loop:
 cmpl $0, %eax                   # Check for last item of list 
 je loop_exit
 incl %edi                       # load next value into register 
 movl data_items(,%edi,4), %eax  
 cmpl %ebx, %eax                 # Compare values 
 jle start_loop                  # jump to loop start if new value isnt bigger 
 movl %eax, %ebx                 # move value is new value is bigger 
 jmp start_loop                  # jump to loop start 

loop_exit:
 # %ebx is the status code for the exit sys call and it already has max number 
 movl $1, %eax                   # loading 1 into eax as 1 is the exit syscall
 int $0x80                       # call to the linux kernel to interupt program 


