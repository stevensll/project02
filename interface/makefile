all: test.o library.o
	gcc -o library test.o library.o

test.o: test.c library.c library.h
	gcc -c test.c

library.o: library.c library.h
	gcc -c library.c

run: 
	./library