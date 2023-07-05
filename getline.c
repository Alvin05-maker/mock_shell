#include "main.h"
/*
 * get_line - reads the line on the command-line
 *
 * Return: returns the pointer to the line read on the command line
 */
char *get_line()
{
        char *lineptr = NULL;
        size_t buf = 0; /*buffer size allocated by getline()*/
        ssize_t charsRead;
	
	charsRead = getline(&lineptr, &buf, stdin);
        if (charsRead == -1)
        {
                if (feof(stdin))
                {
			write(STDOUT_FILENO, "\r", 1);
			exit(0);/*EOF is received*/
                }
                else
                {
                        perror("can't read line");
			exit(0);
                }
        }
	return lineptr;
}
