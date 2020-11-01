#include "editor.h"

int write_file(char * filename) {
  FILE *fp;
  char *in_str = malloc(1);
  int c;
  int i = 0;
  fp = fopen("tmp", "w");
  if (!fp) {
    return 1;
  }
  while ((c = getchar()) != EOF) {
    in_str[i++] = c;
    in_str = realloc(in_str, i+1);
  }
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
