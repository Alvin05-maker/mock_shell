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

/* builtins */
ssize_t _getline(char **buffer, size_t *n, FILE *);

/*builtin () prototypes*/
int my_cd(char **argv);
int my_exit(char **argv);

/* string functions*/
char *_strdup(char *str);
char *_strcpy(char *dest, char *origin);
char *_strcat(char *dest, char *origin);
int _strcmp(char *str1, char *str2);
int _strlen(char *str);

char *find_path(char *cmd);
char *_getenv(char *name);

extern char **environ;

void *_realloc(void *ptr, unsigned int prev_size, unsigned int curr_size);
int init_process(char **argv);

/*functions in main*/
void myshell_loop(void);
char **tokenize_string(char *lineptr);
int execute_cmd(char **argv);

/**
 * struct builtins - a struct representing a builtin function
 * @name: name of builtin
 * @func: function associated for each builtin
 */
typedef struct builtins
{
	char *name;
	int (*func)(char **argv); /* function pointer */

} builtin_t;

/**
 * struct global_vars - a struct where each member is a global variable
 * @error_num: error number
 * @IN_BUFFSIZE: buffer size used for malloc allocation for getline
 */
typedef struct global_vars
{
	int error_num;
	size_t IN_BUFFSIZE;

} g_vars_t;

extern g_vars_t shell_data; /* global variable */

/*** utility functions ***/
char *_is_in_env(char *name);
int (*get_func(char *name))(char **argv);
void memcheck(char **buffer, size_t nread);
void assign_buffer(char *buffer, char **lineptr,
		size_t n_buff, size_t *n_lineptr);

/***error functions **/
void print_error(char **argv);
void print_integer(int num);
int count_digits(int num);

#endif

