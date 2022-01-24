all: main.o
	gcc -o main main.o `sdl2-config --cflags --libs` -lSDL2_mixer

main.o: main.c
	gcc -c main.c `sdl2-config --cflags --libs` -lSDL2_mixer

run:
	./main
