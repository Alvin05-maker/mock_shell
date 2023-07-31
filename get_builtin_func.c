#include "main.h"

/**
 * get_func - function gets the appropriate function for a builtin
 * @name: builtin name
 *
 * Return: pointer to a function that returns int and takes char ** as argument
 */
int (*get_func(char *name))(char **argv)
{
	builtin_t arr_funcs[] = {
		{ "exit", my_exit },
		{ "cd", my_cd }
	};

	int arr_size, i;

	arr_size = 2;
	i = 0;
	while (i < arr_size)
	{
		if (_strcmp(arr_funcs[i].name, name) == 0)
			return (arr_funcs[i].func);
		i++;
	}
	return (NULL);
}

