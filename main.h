#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WRITE_FILE_COMMAND 'a'
#define SAVE_FILE_COMMAND 's'
#define QUIT_PROGRAM_COMMAND 'q'
#include <unistd.h>

int read_file(char * filename);
int write_file(char * filename);
int save_file(char * filename);
int command_mode(char * filename);
int copy_file(char * filename);
