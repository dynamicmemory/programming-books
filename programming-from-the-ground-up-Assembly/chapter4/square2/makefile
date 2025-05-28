all: main

main: main.o square.o
	ld -m elf_i386 -o main main.o square.o

main.o: main.s 
	as --32 main.s -o main.o 

square.o: square.s 
	as --32 square.s -o square.o

clean:
	rm -f main.o main square.o
