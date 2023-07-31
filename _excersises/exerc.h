#ifndef EXERC_H
#define EXERC_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
/* builtins */
#include <sys/wait.h>

/* macros */
#define TOKEN_BUFFSIZE 1024

#define IN_BUFFERSIZE 1024

int get_ppid();
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
ssize_t _getline(char **buffer, size_t *n, FILE *stream);
char **tokenize_str(char *line);
void free_tokens(char **toks);
void mem_check(char **buffer, size_t *n, size_t nread);
void assign_buffer(char *buffer, char **lineptr, size_t n_buff, size_t *n_lineptr);

#endif

