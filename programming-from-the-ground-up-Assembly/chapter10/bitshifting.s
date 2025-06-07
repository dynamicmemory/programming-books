#Note - assume that the reg %ebx holds preference

movl %ebx, %eax # This copies the information into eax so we dont lose the original data

shr $1, %eax # Shift right the number in the first reg, shift num in sec reg 

andl $0b0000000000000000000000000000000001, %eax # Mask the value 
cmpl $0b0000000000000000000000000000000001, %eax # check its value 

je yes_there_is_a_match 

jmp no_there_is_no_match 



