.include "linux.s"
.include "record-def.s"

.section .data 
input_file_name:
  .ascii "test.dat\0"

output_file_name:
  .ascii "testout.dat\0"

.section .bss 
.lcomm record_buffer, RECORD_SIZE 

#Stack offsets of local variables 
.equ ST_INPUT_DESCRIPTOR, -4
.equ ST_OUTPUT_DESCRIPTOR, -8

.section .text 
.globl _start
_start:
  movl %esp, %ebp
  subl $8, %esp 

  movl $SYS_OPEN, %eax 
  movl $input_file_name, %ebx
  movl $0, %ecx
  movl $0666, %edx 
  int $CALL_LINUS 

  movl %eax, ST_INPUT_DESCRIPTOR(%ebp)

  movl $SYS_OPEN, %eax 
  movl $output_file_name, %ebx 
  movl $0101, %ecx 
  movl $0666, %edx 
  int $CALL_LINUS

  loop:
    pushl ST_INPUT_DESCRIPTOR(%ebp)
    pushl $record_buffer
    call read 
    addl $8, %esp 

    cmpl $RECORD_SIZE, %eax
    jne end 

    incl record_buffer + RECORD_AGE 

    pushl ST_OUTPUT_DESCRIPTOR(%ebp)
    pushl $record_buffer
    call write 
    addl $8, %esp 

    jmp loop

  end:
    movl $1, %eax 
    xorl %ebx, %ebx 
    int $0x80 
