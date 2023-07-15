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
	char *lineptr = NULL;
	char **argv;
	int stat;
	char *prompt = "$";
	size_t buf = 0; /*buffer size allocated by getline()*/
        ssize_t charsRead;

	do {
		if (isatty(STDIN_FILENO))
		{
			write(STDIN_FILENO, prompt, _strnglen(prompt));
			fflush(stdout);
		}
		charsRead = getline(&lineptr, &buf, stdin);
		if (charsRead == -1)
		{
			if (feof(stdin))
			{
				write(STDOUT_FILENO, "\r", 1);
				exit(0);/*EOF is received*/
			}
			else
			{
				perror("can't read line");
				exit(0);
			}
		}
		argv = tokenize_string(lineptr);
		stat = execute_cmd(argv);

		free(lineptr);
		free(argv);
	} while (stat);
}
