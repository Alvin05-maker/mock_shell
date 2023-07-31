#include "exerc.h"

/**
 * main - run commands with their full path, without any argument
 * ac: size of args
 * av: array of args
 *
 * Return: success
 */
int main(int __attribute__((unused)) ac, char __attribute((unused)) **av,
		char **envp)
{
	ssize_t nread;
	char *buffer;
	size_t n;
	pid_t child_pid;
	char **argv;
	int status;

	buffer = NULL;
	n = 0;
	printf("/$ ");

	while ((nread = getline(&buffer, &n, stdin)) != -1)
	{
		argv = tokenize_str(buffer);

		child_pid = fork(); /* create new process */

		if (child_pid == -1) /* fork failed */
			return (EXIT_FAILURE);

		if (child_pid == 0) /* child proccess is running */
		{
			if ((execve(argv[0], argv, envp)) != -1)
				perror("Error");
		}
		else
			wait(&status);

		printf("/$ ");
	}

	free(buffer);
	free(argv);
	return (0);
}

/**
 * free_token - free array of tokens
 * @tokens - array of tokens
 *
 * Return: nothing
 */
void free_tokens(char **toks)
{
	int i;

	for (i = 0; toks[i] != NULL; i++)
		free(toks[i]);

	/*free the memory allocated for the toks array */
	free(toks);
}

