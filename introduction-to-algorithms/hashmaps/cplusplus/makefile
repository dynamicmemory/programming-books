main: main.cc linkedlist.o
	g++ main.cc -o main 

linkedlist.o: linkedlist.h node.h
	g++ linkedlist.h -o linkedlist.o

clean:
	rm main linkedlist.o
