#include <stdio.h>
#include <stdlib.h>

int write_file(char * filename) {
  FILE *fp;
  system("touch tmp_fp");
  char *in_str = malloc(1);
  int c;
  int i = 0;
  fp = fopen(tmp_fp, "a");
  if (!fp) {
    return 1;
  }
  while ((c = getchar()) != EOF) {
    in_str[i++] = c;
    in_str = realloc(in_str, i+1);
  }
  in_str[i] = '\0';
  fprintf(tmp_fp, "%s", in_str);
  return 0;
}
int save_file(char * filename) {
  char buff[100000];
  fgets(buff,100000,tmp_fp);
  FILE *fp;
  fp = fopen(filename, "a");
  
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
  while ((b = getchar()) != "q")  {
    
    if ((b = getchar()) == 'a') {
      if ((b = getchar()) == '\n') {
	write_file(argv[1]);
      }
    }
  }
       
}

