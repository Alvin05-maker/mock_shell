#include "main.h"

/**
 * execute_cmd - seeks to execute builtin functions
 * @argv: array of command-line arguments passed to the program
 *
 * Return: return to initiation of process if the command is not builtin
 */
int execute_cmd(char **argv)
{
	int (*builtin_func)(char **); /* function pointer to
						* hold the address of a builtin function
						*/

	if (argv[0] == NULL) /* no command */
		return (1);

	builtin_func = get_func(argv[0]); /* get the builtin function */

	if (builtin_func) /* if valid builtin */
		return (builtin_func(argv));

	return (init_process(argv));
}

/**
 * init_process - initiates the process
 *
 * @toks: array of command-line arguments passed to the program
 * Return: 1 on success
 */
int init_process(char **toks)
{
	int stat;
	pid_t pid;
	char *command_path;

	command_path = find_path(toks[0]);

	if (command_path == NULL) /* invalid command */
	{
		shell_data.error_num += 1;
		print_error(toks);
		free(command_path);
		return(1);
	}

	pid = fork();

	if (pid == 0) /* if child */
	{
		if (execve(command_path, toks, environ) == -1)
		{
			perror("hsh");
			free(command_path);
			exit(127);
		}
	}
	else if (pid < 0) /* error: fork fail */
	{
		perror("hsh");
	}

	else /* parent */
	{
		do {
			waitpid(pid, &stat, WUNTRACED); /* wait for child process to exit
								* or get terminated by a signal
								*/
		} while (!WIFEXITED(stat) && !WIFSIGNALED(stat));
	}
	free(command_path);
	return (1);
}

