all: main.o cmd.o
	gcc -o main main.o cmd.o `sdl2-config --cflags --libs` -lSDL2_mixer

main.o: main.c cmd.c cmd.h
	gcc -c main.c `sdl2-config --cflags --libs` -lSDL2_mixer

cmd.o: cmd.c cmd.h
	gcc -c cmd.c

run:
	./main