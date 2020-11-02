Basic text editor written in C. At the moment, it has only very basic functionality: to read a file, and append and save some text to it using the 'a' and 's' commands. Work on extra functionality is in progress. 

If you are using GCC, just run `make` to create the executable, which will be called "editor".
To use the text editor, run executable and provide the name of the file. For example, in Bash with executable in current directory, do `./editor FILENAME`. To append text, type in `a`, then `Enter`. Write any text, and to signify EOF, use appropriate EOF sequence. For example, in Bash, it will be `Ctrl-d`, while in cmd, it is `Ctrl-z` then `Enter`.
