.section .data 
list: .long 45,45,45,67,22,22,1
list2: .long 45
list3: .long 45,45,45,67,22,22,1,33,233,2

.section .text 

.globl _start 
.globl max 
_start:
  
  pushl $list 
  pushl $7
  call max
  addl $8, %esp 

  pushl $list2
  pushl $1
  call max 
  addl $8, %esp 

  pushl $list3 
  pushl $10 
  call max 
  addl $8, %esp 

  movl %eax, %ebx
  movl $1, %eax 
  int $0x80 




/*
.section .data
list: .long 69, 72, 31, 44, 90, 1, 55 

.section .text 

.globl _start 
_start:
  movl $list, %edi
  movl $list, %esi
  movl (%edi), %ebx

  addl $28, %esi 

loop:
  addl $4, %edi

  cmpl %esi, %edi 
  je end 

  movl (%edi), %eax 
  cmpl %eax, %ebx 
  jge loop 

  movl %eax, %ebx
  jmp loop 

end:
  movl $1, %eax 
  int $0x80

  */
