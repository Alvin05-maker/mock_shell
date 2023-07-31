#include "exerc.h"

/**
 * main - executes the command 'ls -l /tmp' in 5 different child processes.
 * @ac: size of av
 * @av: array of args
 * @envp: array of enviroment variables (key = value)
 *
 * Return: 0 on success
 */
int main(int __attribute__((unused)) ac, __attribute__
		((unused)) char **av, char **envp)
{
	pid_t child_pid;
	int status, idx;
	char *argv[]  = { "/bin/ls", NULL };

	idx = 0;
	while (idx < 5)
	{
		child_pid = fork(); /* create new process */

		if (child_pid == -1) /* fork failed */
			return (EXIT_FAILURE);

		if (child_pid == 0) /* child proccess is running */
		{
			if ((execve(argv[0], argv, envp)) != -1)
				perror("Error");

		}
		else
			wait(&status); /* wiat for child to terminate */

		idx++;
			
	}
	return (EXIT_SUCCESS);
}

