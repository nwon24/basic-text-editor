#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

#define WRITE_FILE_COMMAND 'a'
#define SAVE_FILE_COMMAND 's'
#define QUIT_PROGRAM_COMMAND 'q'
#define NEW_LINE_CHAR '\n'
#define MAX_BUFF_SIZE 100000


int read_file(char * filename);
int write_file(char * filename);
int save_file(char * filename);
int command_mode(char * filename);
int copy_file(char * filename);
int open_file(char * filename);
int part_copy(char * filename, int num);
void clear();
