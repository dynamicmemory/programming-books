.section .data 

.equ SYS_EXIT, 1 
.equ SYS_OPEN, 5
.equ SYS_READ, 3
.equ SYS_WRITE, 4

.equ O_CREAT_WRONLY_TRUNC, 03101

.equ STDIN, 0
.equ STDOUT, 1 

.equ CALL_LINUS, 0x80

.section .bss 

.equ BUFFERSIZ, 500 
.lcomm BUFFER, BUFFERSIZ 

.section .text 

.equ ARGC, 0
.equ ARGV_0, 4
.equ ARGV_1, 8 

.globl _start 
_start: 
  movl %esp, %ebp

  subl $4, %esp

  movl $SYS_OPEN, %eax 
  movl ARGV_1(%ebp), %ebx 
  movl $O_CREAT_WRONLY_TRUNC, %ecx
  movl $0666, %edx 
  int $CALL_LINUS

  movl %eax, -4(%ebp) # storing the fd 

  loop:


      movl $SYS_READ, %eax 
      movl $STDIN, %ebx 
      movl $BUFFER, %ecx
      movl $BUFFERSIZ, %edx
      int $CALL_LINUS

      cmpl $0, %eax
      je end

      movl %eax, %edx  # copy the size of the buffer into edx 
      movl $SYS_WRITE, %eax 
      movl -4(%ebp), %ebx 
      movl $BUFFER, %ecx 
      int $CALL_LINUS
      
      jmp loop
  end:
      movl $SYS_EXIT, %eax 
      xorl %ebx, %ebx 
      int $CALL_LINUS


# Function to read in from a file 
# Function to write out file to stdout 
# main rountine to ask for instuction
# Function to get input from stdin 
# Function to write to a file 
# 

