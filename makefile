all:
	gcc -Isrc/Include -Lsrc/lib -o tester tester.c -lmingw64 -lSDL2main -lSDL2