#include "main.h"

/**
 * _is_in_env - check if an environment variable is in  environ
 * @name: name of environment variable
 *
 * Return: pointer to environment variable if it exits or NULL if not
 */
char *_is_in_env(char *name)
{
	int i, j;

	if (name == NULL)
		return (NULL);

	for (i = 0; environ[i] != NULL; i++) /* for each environment variable */
	{
		j = 0;
		/* loop thru the name(arg) and find if it's a match */
		while (name[j])
		{
			/* break out of loop if it's not a match */
			if (name[j] != environ[i][j])
				break;

			/**
			 * compare the next chars
			 * if we're at the end of the name and next environ char is =
			 */
			if (name[j + 1] == '\0' && environ[i][j + 1] == '=')
				return (environ[i]);

			j++;
		}
	}
		return (NULL); /* not an enviromental variable */
}

/**
 * _getenv - get the value of an environment variable
 * @name: name of variable
 *
 * Return: value of environment variable: char *
 */
char *_getenv(char *name)
{
	size_t name_len = _strlen(name);
	char *env_var;

	env_var = _is_in_env("PATH");

	if (!env_var) /* not an enviroment variable */
		return (NULL);

	return (&env_var[name_len]);
}

