.section  .data 

helloassembly:
  .ascii "hello assembly\n\0"

.section .text 

.globl _start 
_start:
  pushl $helloassembly
  call printf

  pushl $0
  call exit 
