.section .text 
.globl max 
max:
  pushl %ebp
  movl %esp, %ebp

  movl 8(%ebp), %esi 
  movl 12(%ebp), %ecx
  decl %esi
  //movl 12(%ebp), %edi 

  movl (%ecx), %ebx 

  cmpl $0, %esi 
  je end 
  //addl $28, %edi 

loop:
  addl $4, %ecx
  decl %esi  
  cmpl $0, %esi 
  je end 

  movl (%ecx), %eax 
  cmpl %eax, %ebx 
  jge loop 
  movl %eax, %ebx
  jmp loop 
  
end:
  movl %ebx, %eax 
  movl %ebp, %esp 
  popl %ebp 
  ret
