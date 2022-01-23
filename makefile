all: playback.o
	gcc -o playback playback.o

playback.o: playback.c cmd.c cmd.h
	gcc -c playback.c cmd.c

cmd.o: cmd.c
	gcc -c cmd.c 

run:
	./playback