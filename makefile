all:
	gcc -Isrc/include -Lsrc/lib -o tester tester.c -lmingw32 -lSDL2main -lSDL2 -lSDL2_mixer