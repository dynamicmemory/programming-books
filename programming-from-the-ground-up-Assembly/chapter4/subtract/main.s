#Purpose: Subtract two powered numbers 
#Variables:
#Registers:

.section .data

.section .text 

.globl _start
_start:
  pushl $0
  pushl $5
  call power
  addl $8, %esp

  pushl %eax

  pushl $0
  pushl $5
  call power 
  addl $8, %esp 

  pushl %eax

  pushl $0
  pushl $5
  call power
  addl $8, %esp 

  popl %edi 
  popl %ebx 
  addl %edi, %ebx 
  addl %eax, %ebx 


  ; subl %eax, %ebx 
  ; addl %eax, %ebx 

  movl $1, %eax 
  int $0x80


.type power, @function
power:
  pushl %ebp
  movl %esp, %ebp
  subl $4, %esp

  movl 8(%ebp), %ebx
  movl 12(%ebp), %ecx 

  movl %ebx, -4(%ebp)

  cmpl $0, %ecx 
  je zero

#zero:
#  movl $1, %eax 
#  movl %ebp, %esp 
#  popl %ebp
#  ret

# zero: 
#   cmpl $0, %ecx
#   movl $1, -4(%ebp)
#   je end 

loop:
  cmpl $1, %ecx 
  je end 

  movl -4(%ebp), %eax 
  imull %ebx, %eax 
  movl %eax, -4(%ebp)

  decl %ecx 
  jmp loop

end:
movl -4(%ebp), %eax 
movl %ebp, %esp 
popl %ebp 
ret 
