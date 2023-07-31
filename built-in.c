#include "main.h"

/**
 * my_cd - changes the current working directory
 * @argv: command-line arguments passed to the program
 *
 * Return: 1 on sucess
 */
int my_cd(char **argv)
{
	char *homePath = _getenv("HOME");
	char *prevPath = _getenv("PWD");
	char *error = "Previous directory not set.\n";
	char *current_path = getcwd(NULL, 0);

	if (argv[1] == NULL || _strcmp(argv[1], "~") == 0)
	{
		if (chdir(homePath) != 0)
			perror("hsh");
	}
	else if (_strcmp(argv[1], "-") == 0)
	{
		if (prevPath == NULL)
			write(STDERR_FILENO, error, _strlen(error));
		else if (chdir(prevPath) != 0)
			perror("hsh");
	}
	else
	{
		/*changing to a specified directory*/
		if (chdir(argv[1]) != 0)
			perror("hsh");
		else
		{
			/* updating PWD to current directory*/
			if (current_path != NULL)
			{
				setenv("PWD", current_path, 1);
				free(current_path);
			}
			else
				perror("hsh");
		}
	}
	return (1);
}
/**
 * my_exit - exits the shell when the exit command is keyed
 * @argv: array of command-line arguments passed to the program
 * Return: 0 on success
 */
int my_exit(char __attribute__((unused)) **argv)
{
	return (0);
}

