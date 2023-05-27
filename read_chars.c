#include "sys_headers.h"
#include <stdint.h>
/**
 * read_chars - custom getline to accept input from the
 * standard input stream
 * @lineptr: pointer to the line to be retrieved from standard input
 * @buf_sz: current size of the buffer
 * @n: size of buffer for storing input file
 * @stream: standard stream from which input is to be read
 * @buffer_pos: current buffer possion
 * @buffer: preloaded input of stream
 *
 * Return: Returns the number of lines read on success
 */

ssize_t read_chars(char **lineptr, size_t *n, char *buffer,
		size_t *buffer_pos, size_t *buf_sz, FILE *stream)
{
	size_t i = 0;
	int c;
	char *new_ptr = NULL;

	while (1)
	{
		if (*buffer_pos >= *buf_sz)
		{
			*buffer_pos = 0;
			*buf_sz = read(fileno(stream), buffer, BUF_SIZE);
			if (*buf_sz == 0)
				break;
			else if (*buf_sz == SIZE_MAX)
				return (-1);
		}
		c = buffer[(*buffer_pos)++];
		if (i >= *n - 1)
		{
			*n *= 2;
			new_ptr = (char *) realloc(*lineptr, *n);
			if (new_ptr == NULL)
				return (-1);
			*lineptr = new_ptr;
		}
		(*lineptr)[i++] = c;

		if (c == '\n')
			break;
	}

	if (i == 0)
		return (-1);
	(*lineptr)[i] = '\0';
	return (i);
}
