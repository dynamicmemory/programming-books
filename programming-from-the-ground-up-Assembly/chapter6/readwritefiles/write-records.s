.include "linux.s"
.include "record-def.s"

.section .data 

# Constant data of the records we want to write each text data item is padded 
# to the proper length with null (i.e 0) bytes

# .rept is used to pad each item. .rept tells the assembler to repeat the section 
# between .rept and .endr the number of times specified. This is used in thid 
# progtam to add extra null characters at the end of each field to fill it up 

record1:
  .ascii "Fredrick\0"
  .rept 31 #Padding to 40 bytes 
  .byte 0
  .endr 

  .ascii "Bartlett\0"
  .rept 31 # Padding to 40 bytes 
  .byte 0
  .endr

  .ascii "4242 s Prairie\nTulsa, OK 55555\0"
  .rept 209 
  .byte 
  .endr

  .long 45 

record2:
  .ascii "Marilyn\0"
  .rept 32 #Padding to 40 bytes 
  .byte 0
  .endr 

  .ascii "Taylor\0"
  .rept 33 # Padding to 40 bytes 
  .byte 0
  .endr

  .ascii "2224 S Johanna St\nChicago, IL 12345\0"
  .rept 203
  .byte 0
  .endr

  .long 29

record3:
  .ascii "Derrick\0"
  .rept 32 #Padding to 40 bytes 
  .byte 0
  .endr 

  .ascii "McIntire\0"
  .rept 31 # Padding to 40 bytes 
  .byte 0
  .endr

  .ascii "500 W Oakland\nSan Diego, CA 54321\0"
  .rept 206 
  .byte 
  .endr
  
  .long 36

# The name of the fiel we will write too 
file_name:
.ascii "test.dat\0"

.equ ST_FILE_DESCRIPTOR, -4 
.globl _start 

_start:

  movl %esp, %ebp          # Copy the stack pointer to %ebp
  subl $4, %esp            # Allocate space to hodl the fd 

  movl $SYS_OPEN, %eax 
  movl $file_name, %ebx
  movl $0101, %ecx         # This says to create if it doesnt exist and open for writing 
  movl $0666, %edx 
  int $CALL_LINUS 

  movl %eax, ST_FILE_DESCRIPTOR(%ebp)    # Store the fd away 
  
  # Write the records 
  pushl ST_FILE_DESCRIPTOR(%ebp)
  pushl $record1 
  call write 
  addl $8, %esp 

  pushl ST_FILE_DESCRIPTOR(%ebp)
  pushl $record2 
  call write 
  addl $8, %esp 

  pushl ST_FILE_DESCRIPTOR(%ebp)
  pushl $record3 
  call write 
  addl $8, %esp 

  # Close the fd 
  movl $SYS_CLOSE, %eax 
  movl ST_FILE_DESCRIPTOR(%ebp), %ebx 
  int $CALL_LINUS

  # Exit program 
  movl $SYS_EXIT, %eax 
  movl $0, %ebx 
  int $CALL_LINUS
