# Purpose: Convert an integer number to a decimal string for display 
# Input: A buffer large enough to hold the largest possible number an int to convert 
# Output: The buffer will be overwritten with the decimal string 
# Variables: 
# ecx will hold the count of characters processed 
# eax will hold the current value 
# edi will hold the base (10)

.equ ST_VALUE, 8
.equ ST_BUFFER, 12 

.globl integer2string 
.type integer2stringm, @function
integer2string:
  pushl %ebp
  movl %esp, %ebp 

  xorl %eax, %ecx # current char count 
  movl ST_VALUE(%ebp), %eax # move the current val into position 

  movl $10, %edi 

  conversion_loop:
    xorl %edx, %edx  # Division takes place as edx/eax so clear the reg
    
    # divide edx:eax by edi... 10, quotient stored in eax, remainder in edx 
    divl %edi

    # Next is classic ascii math, '0' + number will give the number, so we take 
    # edi and add '0' to it to get the first digit then push it onto the stack 
    addl $'0', %edx 
    pushl %edx 

    incl %ecx 

    # if eax is 0 we got no more converts to do, we done 
    cmpl $0, %eax 
    je end 
    
    # eax is already our number divided by 10 so we are ready to go agane 
    jmp conversion_loop

  end:
    movl ST_BUFFER(%ebp), %edx  # The string is on the stack, now pop vals into buffer 

  reverse_num:
    popl %eax
    movb %al, (%edx) # we push whole reg, but only need a byte, single char. 

    # decrese ecx to know when we are finished (it was counting decimal places)
    decl %ecx 
    # increase edx to next position  
    incl %edx 
    
    # if ecx is 0 then we are at last digit 
    cmpl $0, %ecx
    je giga_end 

    jmp reverse_num 

  giga_end:
    # move the last digit over 
    movb $0, (%edx)
    
    movl %ebp, %esp 
    popl %ebp 
    ret 
