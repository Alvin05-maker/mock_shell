#include "exerc.h"

/**
 * main - program that looks for files in the current PATH
 * @ac: size of av
 * @av: array of args
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	char *pathstring, *dir, *cmd, *pathbuffer;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "Error: Usage: _which filename\n");
		return (EXIT_FAILURE);
	}

	pathstring = getenv("PATH");
	dir = strtok(pathstring, ":");
	cmd = av[1];

	while (dir != NULL)
	{
		pathbuffer = malloc(strlen(dir) + strlen(cmd) + 2);

		if (!pathbuffer) /* malloc fail */
			return (EXIT_FAILURE);

		sprintf(pathbuffer, "%s/%s", dir, cmd); /* concatenate directory and file */

		if (access(pathbuffer, X_OK) == 0) /* if file is an executable */
		{
			printf("%s\n", pathbuffer);
			return (EXIT_SUCCESS);
		}

		dir = strtok(NULL, ":");

		free(pathbuffer);
	}
	return (EXIT_FAILURE);
}

