#include "exerc.h"

/**
 * tokenize_str - split string(line) into words (tokens)
 * @line - line read from command line
 *
 * Return: return pointer to array of tokens
 */
char **tokenize_str(char *line)
{
	int buf = TOKEN_BUFFSIZE, index = 0;
	char **toks = malloc(buf * sizeof(char*));
	char *token;
	const char *delim = " \n\t";

	if (toks == NULL) /* malloc fail */
		return (NULL);

	token = strtok(line, delim);
	while (token != NULL)
	{
		toks[index] = token;
		index++;
		if (index >= buf) /* buffer is full */
		{
			buf += TOKEN_BUFFSIZE;
			toks = realloc(toks, buf * sizeof(char*));

			if (!toks) /* realloc fail */
			{
				return (NULL);
				free(toks);
			}
		}
		token = strtok(NULL, delim);
	}
	toks[index] = NULL;
	return toks;
}

