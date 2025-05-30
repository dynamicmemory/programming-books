#Purpose: This program converts an input file to an output file with all letters 
#          Uppercase 
#Processing: 
# 1) Open the input file 
# 2) Open the output file 
# 4) While we're not at the end of the input file 
#    a) read part of file into our memory buffer. 
#    b) go through each byte of memory if the byte is a lower-case letter, 
#       convert if to uppercase.
#    c) write the memory buffer to output file 

.section .data 

# System call numbers 
.equ SYS_OPEN, 5
.equ SYS_WRITE, 4
.equ SYS_READ, 3 
.equ SYS_CLOSE, 6 
.equ SYS_EXIT, 1 

.equ O_RDONLY, 0
.equ O_CREAT_WRONLY_TRUNC, 03101

# Standard file descriptors 
.equ STDIN, 0 
.equ STDOUT, 1 
.equ STDERR, 2 

.equ LINUX_SYSCALL, 0x80 
.equ END_OF_FILE, 0 

.equ NUMBER_ARGUMENTS, 2 

.section .bss
# Buffer - this is where the data is loaded into from the data file and written 
#          from into the output file. This should never exceed 16,000, for reasons
.equ BUFFER_SIZE, 500
.lcomm BUFFER_DATA, BUFFER_SIZE 

.section .text 

# stack positions 
.equ ST_SIZE_RESERVE, 8 
.equ ST_FD_IN, -4
.equ ST_FD_OUT, -8
.equ ST_ARGC, 0 # Number of arguments 
.equ ST_ARGV_0, 4 # Name of program 
.equ ST_ARGV_1, 8 # Input file name 
.equ ST_ARGV_2, 12 # Output file name 

.globl _start 
_start:

### INITIALIZE PROGRAM ###
# Save the stack pointer
movl %esp, %ebp

# Allocate space for our file descriptors on the stack 
subl $ST_SIZE_RESERVE, %esp

open_files:
open_fd_in:

  ### OPEN INPUT FILE ###
  movl $SYS_OPEN, %eax 
  # input filename into %ebx 
  movl ST_ARGV_1(%ebp), %ebx
  movl $O_RDONLY, %ecx
  movl $0666, %edx 
  int $LINUX_SYSCALL 

store_fd_in:
  # save the given file descriptor
  movl %eax, ST_FD_IN(%ebp)

open_fd_out:
  ### OPEN OUTPUT FILE ###
  movl $SYS_OPEN, %eax
  movl ST_ARGV_2(%ebp), %ebx 
  movl $O_CREAT_WRONLY_TRUNC, %ecx 
  movl $0666, %edx 

  int $LINUX_SYSCALL

store_fd_out:
  movl %eax, ST_FD_OUT(%ebp)

### BEGIN MAIN LOOP ### 
read_loop_begin:
  ### READ IN A BLOCK FROM THE INPUT FILE ### 
  movl $SYS_READ, %eax 
  movl ST_FD_IN(%ebp), %ebx 
  movl $BUFFER_DATA, %ecx
  movl $BUFFER_SIZE, %edx 
  int $LINUX_SYSCALL

###EXIT IF WE REACHED THE END ###
cmpl $END_OF_FILE, %eax 
jle end_loop 

continue_read_loop:
### CONVERT THE BLOCK TO UPPER CASE ###
pushl $BUFFER_DATA
pushl %eax 
call convert_to_upper 
popl %eax 
addl $4, %esp 

### WRITE THE BLOCK OUT TO THE OUTPUT FILE ### 
movl %eax, %edx 
movl $SYS_WRITE, %eax 
movl ST_FD_OUT(%ebp), %ebx 
movl $BUFFER_DATA, %ecx 
int $LINUX_SYSCALL 

### CONTINUE THE LOOP ### 
jmp read_loop_begin 

end_loop:
### CLOSE THE FILES ### 
movl $SYS_CLOSE, %eax 
movl ST_FD_OUT(%ebp), %ebx 
int $LINUX_SYSCALL

movl $SYS_CLOSE, %eax 
movl ST_FD_IN(%ebp), %ebx 
int $LINUX_SYSCALL

### EXIT ### 
movl $SYS_EXIT, %eax 
movl $0, %ebx 
int $LINUX_SYSCALL 


####################
### UPPER CASE SECTION ### 

.equ LOWERCASE_A, 'a'
.equ LOWERCASE_Z, 'z' 
.equ UPPER_CONVERSION, 'A' - 'a'

### STACK STUFF ### 
.equ ST_BUFFER_LEN, 8 
.equ ST_BUFFER, 12 

convert_to_upper:
  pushl %ebp 
  movl %esp, %ebp 

### SET UP VARIABLES ###
movl ST_BUFFER(%ebp), %eax 
movl ST_BUFFER_LEN(%ebp), %ebx 
movl $0, %edi 

# If a buffer with zero length was given to us, just leave 
cmpl $0, %ebx 
je end_convert_loop

convert_loop:
  movb (%eax, %edi, 1), %cl 

  cmpb $LOWERCASE_A, %cl 
  jl next_byte
  cmpb $LOWERCASE_Z, %cl 
  jg next_byte 

  # otherwise convert the byte to uppercase 
  addb $UPPER_CONVERSION, %cl 

  movb %cl, (%eax, %edi, 1)

next_byte:
  incl %edi 
  cmpl %edi, %ebx 

  jne convert_loop 

end_convert_loop:
  movl %ebp, %esp 
  popl %ebp 
  ret 

