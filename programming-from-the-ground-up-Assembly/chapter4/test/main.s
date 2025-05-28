.section .text
.globl _start

_start:
  pushl $6         # square(6)
  call square
  addl $4, %esp    # clean up stack

  movl %eax, %ebx  # result -> ebx (exit code)
  movl $1, %eax    # syscall number for exit
  int $0x80
