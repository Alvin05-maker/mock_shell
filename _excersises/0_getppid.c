#include <stdio.h>
#include <unistd.h>
/**
 * get_ppid - get the id of the parent proccess
 *
 * Return: success
 */
int get_ppid(void)
{
	pid_t ppid;

	ppid = getppid();

	return (ppid);
}

