# all: test.o song.o
# 	gcc -o song test.o song.o

# test.o: test.c song.c song.h
# 	gcc -c test.c

# song.o: song.c song.h
# 	gcc -c song.c

# run: 
# 	./song





all: test.o song.o playlist.o 
	gcc -o test test.o song.o playlist.o

test.o: test.c song.c playlist.c song.h playlist.h
	gcc -c test.c 

song.o: song.c song.h
	gcc -c song.c 

playlist.o: playlist.c playlist.h
	gcc -c playlist.c

run:
	./test