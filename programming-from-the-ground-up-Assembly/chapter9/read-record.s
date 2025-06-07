.section .data

record_buffer_ptr:
  .long 0

.section .text 

.globl read
read:
  pushl %ebp 
  movl %esp, %ebp 

  call allocate_init
  pushl $RECORD_SIZE 
  call allocate 
  movl %eax, record_buffer_ptr
  pushl record_buffer_ptr
