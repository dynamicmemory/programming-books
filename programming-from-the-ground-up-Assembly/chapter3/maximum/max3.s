#Purpose:
#Variables:
#Registers:

.section .data 
list:
 .long 3,1,69,4,9,255,0,44

.section .text 

.globl _start 
_start:

movl $list, %esi # assign first address of list to reg
addl $32, %esi   # add the number of bytes till the end of the list 

movl $list, %edi
movl (%edi), %eax  # dereference the first address and assign to reg 
movl %eax, %ebx

loop:
  addl $4, %edi 
  cmpl %esi, %edi   # compare current list poiinter to end list pointer 
  je end 

  movl (%edi), %eax 
  cmpl %eax, %ebx 
  jge loop 

  movl %eax, %ebx 
  jmp loop

# my defunct first attempt
#  cmpl %esi, %edi 
#  je end 
#  addl $4, %edi 
#  movl (%edi), %eax 
#  cmpl %eax, %ebx
#  jge loop 
#  movl %eax, %ebx 
#  jmp loop

end:
  movl $1, %eax 
  int $0x80
