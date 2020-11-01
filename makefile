CC=gcc
CFLAGS=-I


editor: editor_functions.o editor.o
	$(CC) -o editor editor.c editor_functions.c 
