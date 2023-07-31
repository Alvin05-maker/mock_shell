#include "main.h"
/**
 * print_error - print error message
 * @argv: array of command-line arguments
 *
 * Return: void
 */
void print_error(char **argv)
{
	int i, num;

	num = shell_data.error_num;
	write(STDERR_FILENO, "./hsh", 5);
	write(STDERR_FILENO, ": ", 2);
	print_integer(num);
	write(STDERR_FILENO, ": ", 2);

	for (i = 0; argv[0][i] != '\0'; i++)
	{
		write(STDERR_FILENO, &argv[0][i], 1);
	}
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "not found", 9);
	write(STDERR_FILENO, "\n", 1);
}
/**
 * print_integer - writes the error number integer as a string to stderr
 * @num: the error number;
 *
 * Return: void
 */
void print_integer(int num)
{
	char buffer[20];
	int length = count_digits(num);

	num = shell_data.error_num;
	if (num == 0)
	{
		write(STDERR_FILENO, "0", 1);
		return;
	}
	buffer[length] = '\0';

	while (num != 0)
	{
		buffer[--length] = '0' + (num % 10);
		num /= 10;
	}
	write(STDERR_FILENO, buffer, count_digits(num));
}
/**
 * count_digits - counts the number of digits of the error number
 * @num: the error number
 *
 * Return: the coun of digits
 */
int count_digits(int num)
{
	int count = 0;

	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

