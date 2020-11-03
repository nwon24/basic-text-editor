#include "main.h"

int write_file(char * filename) {
  FILE *fp;
  char *in_str = malloc(1);
  int c;
  int i = 0;
  fp = fopen("tmp", "a");
  while ((c = fgetc(stdin)) != EOF) {
    in_str[i++] = c;
    in_str = realloc(in_str, i+1);
  }
  in_str[i] = '\0';
  fputs(in_str, fp);
  fclose(fp);
  return 0;
}
int save_file(char * filename) {
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
  char buff[MAX_BUFF_SIZE];
  fp = fopen(filename, "a+");
  system("clear");
  while (fgets(buff,MAX_BUFF_SIZE,fp)!=NULL) {
    printf("%s",buff);
  }
  fclose(fp);
  return 0;
}
int command_mode(char * filename) {
  printf("You are in command mode.\n");
  char ch1, ch2;
  char ch;
  read(STDIN_FILENO, &ch1, 1);
  if (ch1 == WRITE_FILE_COMMAND && (ch1 = fgetc(stdin)) == 0x0A) {
    write_file(filename);
    printf("You have written to a file. Your changes are currently saved in a temporary location. Type s to save.\n");
    read(STDIN_FILENO, &ch2, 1);
    if (ch2 == SAVE_FILE_COMMAND) {
      save_file(filename);
      return 0;
    }
    else if (ch2 == QUIT_PROGRAM_COMMAND) {
      remove("tmp");
      exit(1);
    }
  }
}
int copy_file(char * filename) {
  int ch;
  FILE *fp, *fq;
  fp = fopen(filename, "r");
  fq = fopen("tmp", "w");
  while ((ch = fgetc(fp)) != EOF) {
    fputc(ch, fq);
  }
  fclose(fp);
  fclose(fq);
  return 0;
}
int part_copy(char * filename, int num) {
  int nl = 0;
  char ch;
  FILE *fp, *fq;
  fp = fopen("tmp", "w");
  fq = fopen(filename, "r");
  while (nl <= num) {
    ch = fgetc(fq);
    if (ch == '\n') {
      ++nl;
    }
    fputc(ch, fp);
    
  }
  fclose(fp);
  fclose(fq);
  return 0;
}
    
