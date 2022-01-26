all: main.o song.o playlist.o interface.o playback.o cmd.o
	gcc -o main.out main.o song.o playlist.o interface.o cmd.o playback.o `sdl2-config --cflags --libs` -lSDL2_mixer

main.o: main.c song.c playlist.c interface.c song.h playlist.h interface.h playback.c cmd.h
	gcc -c main.c 

song.o: song.c song.h
	gcc -c song.c 

playlist.o: playlist.c playlist.h
	gcc -c playlist.c

interface.o: interface.c interface.h playback.c playback.h cmd.h
	gcc -c interface.c

playback.o: playback.c playback.h cmd.h
	gcc -c playback.c `sdl2-config --cflags --libs` -lSDL2_mixer

cmd.o: cmd.c cmd.h
	gcc -c cmd.c
run:
	./main.out
clean:
	@rm *.o *.out || true