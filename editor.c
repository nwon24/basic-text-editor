#include "editor.h"


int main(int argc, char *argv[]) {
  read_file(argv[1]);
  int b;
  if ((b = getchar()) == 'a') {
    if ((b = getchar()) == '\n') {

      write_file(argv[1]);
    }
  }
  save_file(argv[1]);
  printf("End of program!\n");
    
  
}

