CC=gcc

editor: editor_functions.o editor.o
  $(CC) editor.c editor_functions.c -o editor
