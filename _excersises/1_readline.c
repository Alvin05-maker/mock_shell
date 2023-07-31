#include "exerc.h"

/**
 * main - wait for the user to enter a command, prints it on the next line
 * ac: size of args
 * av: array of args
 *
 * Return: success
 */
int main(int __attribute__((unused)) ac, char __attribute((unused)) **av)
{
	ssize_t nread;
	char *buffer;
	size_t n;

	buffer = NULL;
	n = 0;
	printf("/$ ");

	while ((nread = _getline(&buffer, &n, stdin)) != -1)
	{
		printf("%slen: %ldgetlen: %lu\n", buffer, strlen(buffer), nread);
		printf("/$ ");
	}

	free(buffer);
	return (0);
}

