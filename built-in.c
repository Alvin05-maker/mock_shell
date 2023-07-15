#include "main.h"

char *builtin_arr[] = {
        "cd",
        "exit",
};

int (*builtin_func[]) (char **) = {
  &my_cd,
  &my_exit,
};

int builtins_number() {
  return sizeof(builtin_arr) / sizeof(char *);
}

/*
 * my_cd - changes the current working directory
 * @argv: command-line arguments passed to the program
 * Return: 1 on sucess
 */
int my_cd(char **argv)
{
        char *errstr = "tsh: expected argument to cd\n";

        if (argv[1] == NULL)
        {
                write(STDERR_FILENO, errstr, _strnglen(errstr));
	}
        else
        {
                if (chdir(argv[1]) != 0)
                {
                        perror("tsh");
                }
        }
        return 1;
}
/*
 * my_exit - exits the shell when the exit command is keyed
 * @argv: array of command-line arguments passed to the program
 * Return: 0 on success
 */
int my_exit(char **argv)
{
        if (argv[0])
        {
                /*in case first argument seeks to exit the shell*/
        }
        return 0;
}

/**
 * execute_cmd - seeks to execute builtin functions
 * @argv: array of command-line arguments passed to the program
 * Return: return to initiation of process if the command is not builtin
 */
int execute_cmd(char **argv)
{
        int j;

        if (argv[0] == NULL)
        {
                return 1;
        }
        for (j = 0; j < builtins_number(); j++)
        {
                if (_strngcmp(argv[0], builtin_arr[j]) == 0)
                {
                return (*builtin_func[j])(argv);
                }
        }
        return init_process(argv);
}
