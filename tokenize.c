#include "main.h"
/**
 * tokenize_string - splits the string into tokens(small chunks of words)
 * @lineptr: pointer to the line read from the command-line
 * Return: returns pointer to the array of tokens
 */
char **tokenize_string(char *lineptr)
{
	int buf = TOKEN_BUFFSIZE, index = 0;
	char **toks = malloc(buf * sizeof(char *));
	char *token;
	const char *delim = " \n\t";
	char *error = "tsh: allocation error\n";

	if (toks == NULL)
	{
		write(STDERR_FILENO, error, _strlen(error));
		exit(EXIT_FAILURE);
	}
	token = strtok(lineptr, delim);
	while (token != NULL)
	{
		toks[index] = token;
		index++;
		if (index >= buf)
		{
			buf += TOKEN_BUFFSIZE;
			token = _realloc(token, buf, buf * sizeof(char *));
			if (!toks)
			{
				write(STDERR_FILENO, error, _strlen(error));
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, delim);
	}
	toks[index] = NULL;

	return (toks);
}

