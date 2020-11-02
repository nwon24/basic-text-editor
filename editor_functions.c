#include "main.h"

int write_file(char * filename) {
  FILE *fp;
  char *in_str = malloc(1);
  int c;
  int i = 0;
  fp = fopen("tmp", "w");
  if (!fp) {
    return 1;
  }
  while ((c = fgetc(stdin)) != EOF) {
    in_str[i++] = c;
    in_str = realloc(in_str, i+1);
  }
  printf("End of append!\n");
  in_str[i] = '\0';
  fputs(in_str, fp);
  fclose(fp);
  return 0;
}
int save_file(char * filename) {
  char buff[10000];
  FILE *fp;
  FILE *fp2;
  int c;
  int i = 0;
  char *w_str = malloc(1);
  fp = fopen("tmp", "r");
  fp2 = fopen(filename, "a");
  while ((c = fgetc(fp)) != EOF) {
    w_str[i++] = c;
    w_str = realloc(w_str, i+1);
  }
  w_str[i] = '\0';
  fputs(w_str, fp2);
  fclose(fp);
  fclose(fp2);
  remove("tmp");
  printf("File saved!\n");
  return 0;
}
int read_file(char * filename) {
  FILE *fp;
  char buff[100000];
  fp = fopen(filename, "r");
  if (!fp) {
    return 1;
  }
  system("clear");
  while (fgets(buff,100000,fp)!=NULL) {
    printf("%s",buff);
  }
  fclose(fp);
  return 0;
}
int command_mode(char * filename) {
  printf("You are in command mode.\n");
  char ch1, ch2;
  read(STDIN_FILENO, &ch1, 1);
  if (ch1 == WRITE_FILE_COMMAND) {
    write_file(filename);
    printf("\nYou have written to a file. Type s to save.\n");
    read(STDIN_FILENO, &ch2, 1);
    if (ch2 == SAVE_FILE_COMMAND) {
      save_file(filename);
    }
    else if (ch2 == QUIT_PROGRAM_COMMAND) {
      exit(0);
    }
  }
}
    
