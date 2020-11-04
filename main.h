#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

#define WRITE_FILE_COMMAND 'a'
#define SAVE_FILE_COMMAND 's'
#define QUIT_PROGRAM_COMMAND 'q'
#define INSERT_LINE_COMMAND 'i'
#define READ_FILE_COMMAND 'r'
#define MAX_BUFF_SIZE 100000
#define DELETE_LINE_COMMAND 'd'

int read_file(char * filename);
int write_file();
int save_file(char * filename);
int command_mode(char * filename);
int copy_file(char * filename, char * source);
int open_file(char * filename);
int part_copy_top(char * filename, int num);
int part_copy_bottom(char * filename, int num);
int insert_text(char * filename, int line);
int delete_line(char * filename, int line);
void clear();
