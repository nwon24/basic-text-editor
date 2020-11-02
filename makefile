CC=gcc
CFLAGS=-I

editor: editor_functions.o main.o 
	$(CC) -o editor main.c editor_functions.c 
