# all: test.o song.o
# 	gcc -o song test.o song.o

# test.o: test.c song.c song.h
# 	gcc -c test.c

# song.o: song.c song.h
# 	gcc -c song.c

# run: 
# 	./song



# all: test.o song.o playlist.o 
# 	gcc -o test test.o song.o playlist.o

# test.o: test.c song.c playlist.c song.h playlist.h
# 	gcc -c test.c 

# song.o: song.c song.h
# 	gcc -c song.c 

# playlist.o: playlist.c playlist.h
# 	gcc -c playlist.c

# run:
# 	./test


all: test.o song.o playlist.o interface.o
	gcc -o test test.o song.o playlist.o interface.o

test.o: test.c song.c playlist.c interface.c song.h playlist.h interface.h
	gcc -c test.c 

song.o: song.c song.h
	gcc -c song.c 

playlist.o: playlist.c playlist.h
	gcc -c playlist.c

interface.o: interface.c interface.h
	gcc -c interface.c

run:
	./test