#Purpose: Simple program that exits and returns a status code back to the linux kernal

#INPUT: none

#OUPUT: returns a status code. This can be viewed by typing echo $?
#       after running the program 

#VARIABLES: %eax holds the system call number 
#           %ebx holds the return status

.section .data

.section .text
.globl _start
_start:
movl $0, %eax    #this is the linux kernal command number (system call) for 
                 #exiting a program

movl $1, %ebx    # this is the status number we will return to the operating 
                 # system. Change this around and it will return 
                 # different things to echo $?

int $0x80       # this wakes up the kernel to run the exit command

