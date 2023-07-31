#include "exerc.h"

/**
 * _getline - a custom implementation of C getline func
 * lineptr - buffer to store a line(string)
 * @n: initial size of lineptr
 * 
 * Return: number of chars read
 */
size_t _getline(char **buffer, size_t *n, FILE *stream)
{
	size_t nread, new_size;
	int _char; /* var to store each character from stream */

	new_size = 0;
	/* allocate memory for buffer */
	*buffer = malloc(sizeof(char) * *n);

	if (!buffer || !(*buffer))
		return (-1); /* handle malloc's return */

	/* read each line (character by character) */
	nread = 0;
	while ((_char = getc(stream)) != '\n' && _char != EOF)
	{
		/* check if capacity is enough to store */
		if (nread <= *n)
		{
			new_size = (*n) + 3;
			*buffer = _realloc(*buffer, sizeof(char) * *n, sizeof(char) * new_size);
		}
		(*buffer)[nread] = (char)_char;
		*n = new_size;
		nread++;
	}

	(*buffer)[nread] = '\n';
	(*buffer)[nread + 1] = '\0';
	return (nread);
}

/**
 * _realloc - reallocate memory block using malloc
 * @ptr: old pointer
 * @old_size: initial size
 * @new_size: new size for reallocation
 * Return: pointer to new allocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;
	unsigned int id;

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (!ptr)
		return (malloc(new_size));

	if (new_size > old_size)
		new_ptr = malloc(new_size);

	for (id = 0; id < old_size; id++)
		((char *)new_ptr)[id] = ((char *)ptr)[id];

	free(ptr);
	return (new_ptr);
}

