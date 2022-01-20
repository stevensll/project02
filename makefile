all:
	gcc tester.c -Isrc/include -Lsrc/lib -Wall -lmingw32 -lSDL2main -lSDL2 -o tester