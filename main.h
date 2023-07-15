#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>


#define TOKEN_BUFFSIZE 64
#define BUFFER_SIZE 1024

/*builtin () prototypes*/
int my_cd(char **argv);
int my_exit(char **argv);

/* string functions*/
char *_strngcopy(char *dest, char *origin, int n);
char *_strngcat(char *dest, char *origin, int n);
int _strngcmp(char *str1, char *str2);
int _strnglen(char *str);

char *find_path(char *cmd);
char* my_getline();
char *print_env(char **argv);

extern char **environ;

void *_realloc(void *ptr, unsigned int former_size, unsigned int current_size);
int init_process();
int handle_cmd( char **argv);

/*functions in main*/
void myshell_loop();
char *get_line();
int _putchar(char *c);
char **tokenize_string(char *lineptr);
int execute_cmd(char **argv);

void free_tokens(char **toks);

#endif

