CC=gcc
CFLAGS=-I
editor: main_functions.o main.o
	$(CC) main.o main_functions.o -o editor
main_functions.o: main_functions.c
	$(CC) -c main_functions.c
main.o: main.c
	$(CC) -c main.c
clean:
	rm -f *.o

