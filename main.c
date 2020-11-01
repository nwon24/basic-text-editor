#include <stdio.h>
#include <stdlib.h>

int write_file(char * filename) {
  FILE *fp;
  char *in_str = malloc(1);
  int c;
  int i = 0;
  fp = fopen(filename, "a");
  if (!fp) {
    return 1;
  }
  while ((c = getchar()) != EOF) {
    in_str[i++] = c;
    in_str = realloc(in_str, i+1);
  }
  in_str[i] = '\0';
  fprintf(fp,"%s", in_str);  
  return 0;
}
int save_file(char * filename) {
  char tmp_file_name[] = "tmp_fp";
  char buff[100000];
  FILE *fp;
  FILE *f;
  int c;
  fp = fopen(tmp_file_name, "a");
  f = fopen(filename, "a");
  fgets(buff,100000,fp);
  printf("%s", buff);
  fprintf(f,"%s",buff);
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
int main(int argc, char *argv[]) {
  read_file(argv[1]);
  int b;
  if ((b = getchar()) == 'a') {
    if ((b = getchar()) == '\n') {

      write_file(argv[1]);
    }
  }
    
  
}

