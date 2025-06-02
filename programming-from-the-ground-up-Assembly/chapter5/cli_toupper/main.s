.section .data 

.equ SYS_OPEN, 5
.equ SYS_CLOSE, 6
.equ SYS_READ, 3
.equ SYS_WRITE, 4
.equ SYS_EXIT, 1

.equ STDIN, 0
.equ STDOUT, 1 

.equ CALL_LINUX, 0x80

.section .bss
.equ BUFFERSIZ, 500 
.lcomm BUFFER, BUFFERSIZ 

.section .text 

.globl _start 
_start:
  
  movl %esp, %ebp 
  subl $8, %esp 

  movl $SYS_READ, %eax 
  movl $STDIN, %ebx 
  movl $BUFFER, %ecx 
  movl $BUFFERSIZ, %edx 
  int $CALL_LINUX

  pushl %ecx
  pushl %eax
  call convert_to_upper
  popl %edx 
  popl %ecx 
  // movl %eax, %edx 

  movl $SYS_WRITE, %eax 
  movl $STDOUT, %ebx 
  // movl $BUFFER, %ecx 
  int $CALL_LINUX
  
  movl $SYS_EXIT, %eax
  xorl %ebx, %ebx 
  int $CALL_LINUX

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

