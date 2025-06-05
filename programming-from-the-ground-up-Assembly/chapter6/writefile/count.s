.section .data

.section .text 

.globl count 
count:
  pushl %ebp
  movl %esp, %ebp 
  
  movl 8(%ebp), %edx
  movl $0, %ecx 
  loop:
    movb (%edx), %al
    cmpb $0, %al 
    je end 

    incl %edx
    incl %ecx 

    jmp loop

  end:
    movl %ecx, %eax 
    #movl %ebp, %esp 
    popl %ebp 
    ret
