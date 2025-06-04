.equ fname, 0     #20 bytes in size 
.equ lname, 20    #20 bytes in size 
.equ data_size, 40

.section .data 

file_name:
  .ascii "database.dat\0"

record:
  .ascii "hacker \0"
  .rept 12
  .endr 

  .ascii "mans\0"
  .rept 15 
  .endr 

.section .bss 
.equ buffersiz, 1500
.lcomm buffer, buffersiz 
# .lcomm buffer, data_size

.section .text 

newline:
  .ascii "\n\0"

.equ stdin, 0
.equ stdout, 1
.equ stderr, 2

.equ file_descriptor, -4
# exit = 1 
# read = 3
# write = 4
# open = 5 
# close = 6

.globl _start
_start:
  movl %esp, %ebp
  
  # Open the file
  movl $5, %eax 
  movl $file_name, %ebx
  movl $0x242, %ecx
  movl $0666, %edx
  int $0x80

  pushl %eax    
  movl $30, %edi

loop:
  cmpl $0, %edi 
  je end 
  # Write the record 
  movl $4, %eax 
  movl file_descriptor(%ebp), %ebx 
  movl $record, %ecx 
  movl $data_size, %edx 
  int $0x80 

  movl $4, %eax 
  movl $newline, %ecx
  movl $1, %edx 
  int $0x80

  decl %edi 
  jmp loop

end:
  # Move the pointer to the start of the file again 
  movl $19, %eax
  movl file_descriptor(%ebp), %ebx 
  xorl %ecx, %ecx 
  xorl %edx, %edx 
  int $0x80 

  # Read the record 
  movl $3, %eax 
  movl file_descriptor(%ebp), %ebx
  movl $buffer, %ecx 
  movl $buffersiz, %edx
  int $0x80 
  
  # write to stdout 
  movl %eax, %edx 
  movl $4, %eax 
  movl $1, %ebx 
  movl $buffer, %ecx 
  int $0x80 

  movl $6, %eax 
  movl file_descriptor(%ebp), %ebx 
  int $0x80 

  movl $1, %eax 
  xorl %ebx, %ebx
  int $0x80
    

