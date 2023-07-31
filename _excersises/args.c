#include "exerc.h"

/**
 * main - prints all the arguments, without using ac
 * ac: size of args
 * av: NULL terminated array of strings
 *
 * Return: success
 */
int main(int ac, char **av)
{
	while (*av)
	{
		printf("%s\n", *av);
		av++;
	}
	return (0);
}

