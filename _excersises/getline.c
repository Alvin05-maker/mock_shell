#include "exerc.h"

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
/**
 * _getline - a custom implementation of C getline func
 * @buffer: buffer to store a line(string)
 * @n: initial size of lineptr
 * @stream: input stream
 *
 * Return: number of chars read
 */
ssize_t _getline(char **lineptr, size_t *n, FILE __attribute__((unused)) *stream)
{
	ssize_t nread_ret, nread_t;
	int nread;
	char *buffer;
	char _char;

	nread = nread_t = 0;
	_char  = 'a';

	if (lineptr == NULL || n == NULL)
		return (-1);

	if (nread_t == 0)
		fflush(stdout);

	buffer = malloc(sizeof(char) * IN_BUFFERSIZE);
	if (!buffer)
		return (-1);


	/* mem_check(buffer, n, nread); */

	while (_char != '\n')
	{
		nread = read(STDIN_FILENO, &_char, 1);
		if (nread == -1 || (nread == 0 && nread_t == 0)) /* error or no data to read */
		{
			free(buffer);
			return (-1);
		}

		if (nread == 0 && nread_t != 0) /* no more chars to read */
		{
			nread_t++;
			break;
		}
		
		if (nread_t >= IN_BUFFERSIZE) /* memory full */
			buffer = _realloc(buffer, nread_t, nread_t * 2);

		buffer[nread_t] = _char;
		nread_t += 1;
	}
	buffer[nread_t] = '\0';
	assign_buffer(buffer, lineptr, nread_t, n);	
	nread_ret = nread_t;

	if (nread_ret)
		nread_t = 0;

	return (nread_ret);
}

/**
 * assign_buffer - assign buffer to lineptr
 * @buffer: pointer to char *
 * @lineptr: pointer to pointer to char *
 * @n_buff: size of buffer
 * @n_lineptr: size of lineptr
 *
 * Return: void
 */
void assign_buffer(char *buffer, char **lineptr, size_t n_buff, size_t *n_lineptr)
{
		if (*lineptr == NULL || *n_lineptr < n_buff)
		{
			*lineptr = buffer;
			*n_lineptr = n_buff;
			return;
		}

		strcpy(*lineptr, buffer);
		free(buffer);
}

