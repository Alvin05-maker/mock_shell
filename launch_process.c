#include "main.h"
/**
 * tokenize_string - splits the string into tokens(small chunks of words)
 * @lineptr: pointer to the line read from the command-line
 * Return: returns pointer to the array of tokens
 */
char **tokenize_string(char *lineptr)
{
        int buf = TOKEN_BUFFSIZE, index = 0;
        char **toks = malloc(buf * sizeof(char*));
        char *token;
        const char *delim = " \n\t";
        char *error = "tsh: allocation error\n";

        if (toks == NULL)
        {
                write(STDERR_FILENO, error, _strnglen(error));
                exit(EXIT_FAILURE);
        }
        token = strtok(lineptr, delim);
        while (token != NULL)
        {
                toks[index] = token;
                index++;
                if (index >= buf)
                {
                        if (!toks)
                        {
                                write(STDERR_FILENO, error, _strnglen(error));
                                exit(EXIT_FAILURE);
			}
		}	
                token = strtok(NULL, delim);
        }
        toks[index] = NULL;

	return toks;
}
void free_tokens(char **toks)
{
	int i;
	
	for (i = 0; toks[i] != NULL; i++)
	{
		free(toks[i]);
	}
	/*free the memory allocated for the toks array*/
	free(toks);
}
/*
 * init_process - initiates the process
 *
 * @toks: array of command-line arguments passed to the program
 * Return: 1 on success
 */
int init_process(char **toks)
{
	static int cmd_num = 0;
        pid_t pid;
        int stat;
	char *command_path = find_path(toks[0]);

	cmd_num++;
	pid = fork();
	if (pid == 0)
	{
		if (access(toks[0], X_OK) == 0)
		{
			execve(toks[0], toks, environ);
		}
		else if (command_path != NULL)
		{
			if (execve(command_path, toks, environ) == -1)
			{
				perror("hsh");
				exit(EXIT_FAILURE);
			}
			free(command_path);
		}
		else
		{
			fprintf(stderr, "./hsh: %d: %s: not found\n", cmd_num, toks[0]);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("hsh");
	}
	else
	{
		do {
			waitpid(pid, &stat, WUNTRACED);
		} while (!WIFEXITED(stat) && !WIFSIGNALED(stat));
	}
	return 1;
}
