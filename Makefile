CC = gcc
CFLAGS = -Wall -Wextra

wordle.exe : mainwordle.o fonctions.o
	$(CC) $(CFLAGS) mainwordle.o fonctions.o -o wordle.exe

mainwordle.o : mainwordle.c fonctions.h
	$(CC) $(CFLAGS) -c mainwordle.c

fonctions.o : fonctions.c fonctions.h
	$(CC) $(CFLAGS) -c fonctions.c

clean :
	del *.o
	del wordle.exe