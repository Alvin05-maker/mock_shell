#include "main.h"

/**
 * find_path - function looks for files in the current PATH
 * @cmd: command(filename, filepath)
 *
 * Return: full path to file (executable)
 */
char *find_path(char *cmd)
{
	char *dir, *path, *path_copy, *command_path;
	size_t command_path_lenght = 0;

	/* check if path is already valid */
	if (access(cmd, X_OK) == 0)
		return (_strdup(cmd));

	path = _getenv("PATH");
	command_path = NULL;
	path_copy = _strdup(path);
	dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		command_path_lenght = _strlen(dir) + _strlen(cmd) + 2;
		command_path = malloc(command_path_lenght);

		_strcpy(command_path, dir);
		_strcat(command_path, "/");
		_strcat(command_path, cmd);

		if (access(command_path, X_OK) == 0)
		{
			free(path_copy);
			return (command_path);
		}
		dir = strtok(NULL, ":");

		free(command_path);
	}
	free(path_copy);
	return (NULL);
}

