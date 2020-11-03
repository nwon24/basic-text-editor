#include "main.h"

int write_file(char * filename) {
  FILE *fp;
  char *in_str = malloc(1);
  int c;
  int i = 0;
  printf("Append mode!\n");
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
  char ch1;
  while (ch1 != QUIT_PROGRAM_COMMAND) {
    read(STDIN_FILENO, &ch1, 1);

    if (ch1 == WRITE_FILE_COMMAND && (ch1 = fgetc(stdin)) == '\n') {
      write_file(filename);
      printf("You have written to a file. Your changes are currently saved in a temporary location. Type s to save.\n");
      continue;
    }
    if (ch1 == INSERT_LINE_COMMAND && (ch1 = fgetc(stdin)) == '\n') {
      printf("Enter under which line you would like to insert.\n");
      int l;
      scanf("%d", l);
      insert_text(filename, l);
      printf("Inserted! Press s to save!\n");
      continue;
    }
    if (ch1 == SAVE_FILE_COMMAND) {

      save_file(filename);
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
int part_copy_top(char * filename, int num) {
  int nl = 0;
  char ch;
  FILE *fp, *fq; 
  fp = fopen("tmp", "w");
  fq = fopen(filename, "r");
  while (nl < num) {
    ch = fgetc(fq);
    if (ch == '\n') {
      ++nl;
    }
    fputc(ch, fp);
	  
  }
    
  fclose(fp);
  fclose(fq);
  return num;
}
int part_copy_bottom(char * filename, int num) {
  int nl = 0;
  char ch;
  FILE *fp, *fq;
  fq = fopen(filename, "r");
  fp = fopen("tmp2", "w");
  while (nl < num) {
    ch = fgetc(fq);
    if (ch == '\n') {
      
      ++nl;
    }
  }
  while ((ch = fgetc(fq)) != EOF) {
    fputc(ch, fp);
  }
  fclose(fp);
  fclose(fq);
  
    
  return 0;
}
int insert_text(char * filename, int line) {
  part_copy_top(filename, line);
  part_copy_bottom(filename, line);
  write_file("tmp");
  FILE *fp, *ft, *fq;
  ft = fopen("tmp", "r");
  fq = fopen("tmp2", "r");
  fp = fopen(filename, "w");
  char ch;
  while ((ch = fgetc(ft)) != EOF) {
    fputc(ch, fp);
  }
  fclose(fp);
  fp = fopen(filename, "a");
  while ((ch = fgetc(fq)) != EOF) {
    fputc(ch, fp);
  }
  fclose(fp);
  fclose(ft);
  fclose(fq);
    
  return 0;
}
  
