.equ fname, 0     #20 bytes in size 
.equ lname, 20    #20 bytes in size 
.equ data_size, 40

.section .data 

record:
  .ascii "hacker\0"
  .rept 13
  .endr 

  .ascii "mans\0"
  .rept 15 
  .endr 

file_name:
.ascii "database.dat"

.section .bss 
# .equ buffersiz, 500
.lcomm buffer, data_size

.section .text 

.equ stdin, 0
.equ stdout, 1
.equ stderr, 2

# exit = 1 
# read = 3
# write = 4
# open = 5 
# close = 6

.globl _start
_start:
  # Open the file
  movl $5, %eax 
  movl $file_name, %ebx
  movl $0x242, %ecx
  movl $0666, %edx
  int $0x80

  movl %eax, %edi
  # Write the record 
  movl $4, %eax 
  movl %edi, %ebx 
  movl $record, %ecx 
  movl $data_size, %edx 
  int $0x80 

  # Move the pointer to the start of the file again 
  movl $19, %eax
  movl %edi, %ebx 
  xorl %ecx, %ecx 
  xorl %edx, %edx 
  int $0x80 

  # Read the record 
  movl $3, %eax 
  movl %edi, %ebx
  movl $buffer, %ecx 
  movl $data_size, %edx
  int $0x80 
  
  # write to stdout 
  movl %eax, %edx 
  movl $4, %eax 
  movl $1, %ebx 
  movl $buffer, %ecx 
  int $0x80 

  movl $1, %eax 
  xorl %ebx, %ebx
  int $0x80
    
  
