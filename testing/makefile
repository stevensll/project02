all: main.o cmd.o
	gcc -o main main.o cmd.o 

main.o: main.c cmd.c cmd.h
	gcc -c main.c 

cmd.o: cmd.c cmd.h
	gcc -c cmd.c

run:
	./main