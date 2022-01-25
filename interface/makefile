# all: main.o song.o
# 	gcc -o song main.o song.o

# main.o: main.c song.c song.h
# 	gcc -c main.c

# song.o: song.c song.h
# 	gcc -c song.c

# run: 
# 	./song



# all: main.o cmd.o
# 	gcc -o main main.o cmd.o `sdl2-config --cflags --libs` -lSDL2_mixer

# main.o: main.c cmd.c cmd.h
# 	gcc -c main.c `sdl2-config --cflags --libs` -lSDL2_mixer

# cmd.o: cmd.c cmd.h
# 	gcc -c cmd.c

# run:
# 	./main

# # all: main.o song.o playlist.o 
# 	gcc -o main main.o song.o playlist.o

# main.o: main.c song.c playlist.c song.h playlist.h
# 	gcc -c main.c 

# song.o: song.c song.h
# 	gcc -c song.c 

# playlist.o: playlist.c playlist.h
# 	gcc -c playlist.c

# run:
# 	./main


all: main.o song.o playlist.o interface.o playback.o
	gcc -o main.out main.o song.o playlist.o interface.o playback.o `sdl2-config --cflags --libs` -lSDL2_mixer

main.o: main.c song.c playlist.c interface.c song.h playlist.h interface.h playback.c
	gcc -c main.c 

song.o: song.c song.h
	gcc -c song.c 

playlist.o: playlist.c playlist.h
	gcc -c playlist.c

interface.o: interface.c interface.h playback.c playback.h
	gcc -c interface.c

playback.o: playback.c playback.h
	gcc -c playback.c `sdl2-config --cflags --libs` -lSDL2_mixer

run:
	./main.out
clean:
	@rm *.o *.out || true