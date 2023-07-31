#include "main.h"
/**
 * _realloc - reallocates a memory block
 * @ptr: pointer to previous malloc'ed block
 * @prev_size: byte size of previous block
 * @curr_size: byte size of new block
 *
 * Return: pointer to the new block
 */
void *_realloc(void *ptr, unsigned int prev_size, unsigned int curr_size)
{
	char *p;

	if (!ptr)
		return (malloc(curr_size));
	if (!curr_size)
		return (free(ptr), NULL);
	if (curr_size == prev_size)
		return (ptr);

	p = malloc(curr_size);
	if (!p)
		return (NULL);

	prev_size = prev_size < curr_size ? prev_size : curr_size;
	while (prev_size--)
		p[prev_size] = ((char *)ptr)[prev_size];
	free(ptr);

	return (p);
}

