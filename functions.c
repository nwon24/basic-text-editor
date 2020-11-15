#include "main.h"
/* core functions for text editor */

int write_file()
{
  	FILE *fp;
  	char *in_str = malloc(1);
  	int c;
  	int i = 0;
  	printf("Append mode!\n");
  	fp = fopen("tmp", "a");
  	while ((c = fgetc(stdin)) != EOF) {
    		in_str[i++] = c;
    		in_str = realloc (in_str, i+1);
  	}
  	in_str[i] = '\0';
  	fputs(in_str, fp);
  	fclose(fp);
  	return 0;
}
int save_file(char *filename)
{
  	copy_file("tmp", filename);
  	printf("File saved!\n");
  	return 0;
}
int read_file(char *filename)
{
  	FILE *fp;
  	char buff[MAX_BUFF_SIZE];
  	fp = fopen(filename, "a+");
 	system("clear");
  	while (fgets(buff,MAX_BUFF_SIZE,fp) != NULL) {
    		printf("%s", buff);
	}
  	fclose(fp);
  	return 0;
}
int command_mode(char *filename)
{
  	printf("You are in command mode.\n");
  	char ch1;
  	while (ch1 != QUIT_PROGRAM_COMMAND) {
    		read(STDIN_FILENO, &ch1, 1);

    		if (ch1 == WRITE_FILE_COMMAND && (ch1 = fgetc(stdin)) == '\n') {
      			write_file();
      			printf("You have written to a file. Your changes are currently saved in a temporary location. Type s to save.\n");
    		}
    		if (ch1 == READ_FILE_COMMAND && (ch1 = fgetc(stdin)) == '\n') {
      			read_file(filename);
    		}
    		if (ch1 == INSERT_LINE_COMMAND && (ch1 = fgetc(stdin)) == '\n') {
      			printf("Enter under which line you would like to insert.\n");
            int l;
      			scanf("%d", &l);
            char ch;
            if ((ch = getchar()) == '\n') {  
        		    insert_text(filename, l);
      			    printf("Inserted! Press s to save!\n");
            }
    		}
    		if (ch1 == DELETE_LINE_COMMAND && (ch1 = fgetc(stdin)) == '\n') {
      			printf("Enter the line which you want to delete:\n");
      			int l;
      			scanf("%d", &l);
      			delete_line(filename, l);
      			printf("Deleted! Press s to save!\n");
    		}  
			if (ch1 == CHANGE_LINE_COMMAND && (ch1 = fgetc(stdin)) == '\n') {
				printf("Enter the line which you want to change.\n");
				int l;
				scanf("%d", &l);
				char ch;
				if ((ch = fgetc(stdin)) != EOF) {
					change_line(filename, l);
					printf("Line changed! Press s to save!\n");
				}
			}
    		if (ch1 == SAVE_FILE_COMMAND) {

      			save_file(filename);
    		}
  	}
}

int copy_file(char *filename, char *source)
{
  	int ch;
  	FILE *fp, *fq;
  	fp = fopen(filename, "r");
  	fq = fopen(source, "w");
  	while ((ch = fgetc(fp)) != EOF) {
    		fputc(ch, fq);
	}
  	fclose(fp);
  	fclose(fq);
  	return 0;
}

int part_copy_top(char *filename, int num)
{
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

int part_copy_bottom(char *filename, int num)
{
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
    		fputc (ch, fp);
	}
   	fclose(fp);
 	fclose(fq);
	return 0;
}

int insert_text(char *filename, int line)
{
  	part_copy_top(filename, line);
  	part_copy_bottom(filename, line);
  	write_file();
  	FILE *ft, *fq;
  	ft = fopen("tmp", "a");
  	fq = fopen("tmp2", "r");
  	char ch;
  	while ((ch = fgetc(fq)) != EOF) {
    		fputc(ch, ft);
  	}
  	fclose(fq);
  	fclose(ft);
  	return 0;
}

int delete_line(char *filename, int line)
{
   	part_copy_top(filename, line - 1);
  	part_copy_bottom(filename, line);
  	FILE *fp, *fq;
  	fp = fopen("tmp", "a");
  	fq = fopen("tmp2", "r");
 	char ch;
  	while ((ch = fgetc (fq)) != EOF) {
    		fputc(ch, fp);
	}
  	fclose(fq);
  	fclose(fp);
  	return 0;
}	

int change_line(char *filename, int line)
{
	part_copy_top(filename, line - 1);
	part_copy_bottom(filename, line);
	FILE *fp, *fq;
	fp = fopen("tmp", "a");
	fq = fopen("tmp2", "r");
	write_file();
	char ch;
	while ((ch = fgetc(fq)) != EOF) {
		fputc(ch, fp);
	}
	fclose(fq);
	fclose(fp);
	return 0;
	
}
