CC=gcc
CFLAGS=-I -std=c99
editor: functions.o main.o 
	$(CC) main.o functions.o $(CFLAGS) -o editor
functions.o: functions.c
	$(CC) -c functions.c
main.o: main.c
	$(CC) -c main.c
clean:
	rm -f *.o

