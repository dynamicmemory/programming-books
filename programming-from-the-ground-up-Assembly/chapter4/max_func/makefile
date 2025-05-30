main: main.o max.o 
	ld -m elf_i386 main.o max.o -o main 

main.o: main.s 
	as -32 main.s -o main.o

max.o: max.s 
	as -32 max.s -o max.o

clean: 
	rm -f main.o main max.o
