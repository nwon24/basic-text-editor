#include "edit.h"

/* main text editor function */
int main (int argc, char *argv[])
{
        if (argc == 1) {
                system("clear");
                printf("Must supply filename as argument! (Will create file if doesn't exist).\n");
                return 0;
        }
        copy_file(argv[1], "tmp");
        read_file(argv[1]);
        command_mode(argv[1]);
        remove("tmp");
        remove("tmp2");
}

