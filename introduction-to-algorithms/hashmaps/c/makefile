main: main.c hashmap.o 
	gcc main.c -o main 

hashmap: hashmap.c linkedlist.o
	gcc hashmap.c -o hashmap.o

linkedlist: linkedlist.c node.h 
	gcc linkedlist.c -o linkedlist.o

clean:
	rm main linkedlist.o
