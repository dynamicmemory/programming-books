#Purpose - A program to manage memory usage, allocates and deallocates as needed

.section .data

#### Global Vars ####
heap_begin:
 .long 0 # This points to the beginning of mem we are managing 

current_break:
 .long 0 # This points to one location past the mem we are managing 

#### Struct info ####
.equ HEADER_SIZE, 8 # size of space for mem region header 
.equ HDR_AVAIL_OFFSET, 0 # location of 'available' flag in header 
.equ HDR_SIZE_OFFSET, 4 # locatino of the size field inthe header 

#### Constants ####
.equ UNAVAILABLE, 0 # number used to mark space given out 
.equ AVAILABLE, 1   # number used to mark space returned and available to give 
.equ SYS_BRK, 45 
.equ LINUX_SYSCALL, 0x80

.section .text 

#### Functions ####

##allocate_init##
# Purpose - call this function to initializer functions.... no params and no return 

.globl allocate_init
.type allocate_init, @function 
allocate_init:
 pushl %ebp
 movl %esp, %ebp 

 movl $SYS_BRK, %eax # if BRK is called with 0 in ebx, it rets last usable addr
 movl $0, %ebx 
 int $LINUX_SYSCALL

 # eax now has last valid address, we want mem loc one after that 
 incl %eax 

 # point our params to the break (one past last usable mem loc)
 movl %eax, current_break
 movl %eax, heap_begin

 movl %ebp, %esp 
 popl %ebp
 ret 

## allocate ##
# Purpose - This func will grab new mem if none free, will ask linux for new block 
# Params - only one, size of the mem block we want to allo 
# Ret - The addr of the allo mem block in eax, if none available ret 0 
# Vars 
# ecx - hold size of req mem 
# eax - current mem region being examined 
# ebx - current brk point 
# edx - size of curr mem region 

.globl allocate 
.type allocate, @function 
.equ ST_MEM_SIZE, 8 

allocate:
 pushl %ebp 
 movl %esp, %ebp 

 movl ST_MEM_SIZE(%ebp), %ecx   # size we are looking for 
 movl heap_begin, %eax          # current loc we are searching 
 movl current_break, %ebx       # loc of current mem break

 alloc_loop:
  # if these are ==, we need more mem as we are at current max 
  cmpl %ebx, %eax
  je move_break 

  movl HDR_SIZE_OFFSET(%eax), %edx # grab the size of the curr mem loc 

  # If the space is unavilable then go to the next location
  cmpl $UNAVAILABLE, HDR_AVAIL_OFFSET(%eax)
  je next_location 

  # If space is available compare size to needed, if its big enough, allocate 
  cmpl %edx, %ecx 
  jle allocate_here 

 next_location:
  addl $HEADER_SIZE, %eax  # Getting the total size of mem region. few flags 
  addl %edx, %eax          # add some bytes to the requested size 

  jmp alloc_loop 

 allocate_here:
  movl $UNAVAILABLE, HDR_AVAIL_OFFSET(%eax)
  addl $HEADER_SIZE, %eax # move eax to the start of the new usable mem 

  movl %ebp, esp 
  popl %ebp
  ret 

 move_break:               # if we make it here then we ran out of mem and need linux to give 
  addl $HEADER_SIZE, %ebx  # us more, ebx holds the current endpoint of data ecx holds size 
  addl %ecx, %ebx          # Add space for the headers and space to the break for req size 

  # Save all valuable registers 
  pushl %eax 
  pushl %ecx
  pushl %ebx 
  
  # call linus for more mem 
  movl $SYS_BRK, %eax 
  int $LINUX_SYSCALL
  
  # If it ret 0.... linus hates us and something terrible happened.
  cmpl $0, %eax 
  je error 

  # get our shit back 
  popl %ebx
  popl %ecx 
  popl %eax 

  movl $UNAVAILABLE, HDR_AVAIL_OFFSET(%eax) # Mark new mem as unavilable as we bout to use it 
  movl %ecx, HDR_SIZE_OFFSET(%eax) # Set the size of the mem 
  addl $HEADER_SIZE, %eax  # eax now holds addr to start of new mem 
  movl %ebx, current_break # set the new break spot 

  movl %ebp, %esp 
  popl %ebp 
  ret 

## deallocate ##
# Purpose - Give back the mem to the pool once we are done with it 
# Params - Only one is the addr of mem we want to return 
# Ret - none 
.globl deallocate
.type deallocate, @function 
.equ ST_MEMORY_SEG, 4 # Stack pos of region to free 

deallocate:
 movl ST_MEMORY_SEG(%esp), %eax # move the param into eax  

 subl $HEADER_SIZE, %eax # adjust for the headers size 

 movl $AVAILABLE, HDR_AVAIL_OFFSET(%eax) # mark it as available 

 ret 



