#include "main.h"
/*
 * main - Entry point to the shell loop
 *
 * Return: 0 on Success
 */
int main(void)
{
	myshell_loop();
	return (0);
}

/*
 * myshell_loop - shell loop
 *
 * Return: return void
 */
void myshell_loop(void)
{
	char *lineptr;
	char **argv;
	int stat;
	char *prompt = "$";

	do {
		if (isatty(STDIN_FILENO))
		{
			write(STDIN_FILENO, prompt, _strnglen(prompt));
			fflush(stdout);
		}
		lineptr = get_line();
		argv = tokenize_string(lineptr);
		stat = execute_cmd(argv);

		free(lineptr);
		free(argv);
	} while (stat);
}
