#include "main.h"


int main(int argc, char *argv[]) {
  int ch;
  if (argc == 1) {
    system("clear");
    printf("Must supply filename as argument! (Will create file if doesn't exist).\n");
    return 0;
  }
  read_file(argv[1]);
  int exit = command_mode(argv[1]);
  read(STDIN_FILENO, &ch, 1);
  while (ch != QUIT_PROGRAM_COMMAND) {
    read_file(argv[1]);
    command_mode(argv[1]);
    read(STDIN_FILENO, &ch, 1);
  }
}

