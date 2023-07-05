#include "main.h"

char *find_path(char *cmd)
{
	char *pathstring = getenv("PATH");
	char *dir = strtok(pathstring, ":");

	while (dir != NULL)
	{
		char *pathbuffer = malloc(_strnglen(dir) + _strnglen(cmd) + 2);

		sprintf(pathbuffer, "%s/%s", dir, cmd);

		if (access(pathbuffer, X_OK) == 0)
		{
			return (pathbuffer);
		}
		dir = strtok(NULL, ":");

		free(pathbuffer);
	}
	return (NULL);
}
