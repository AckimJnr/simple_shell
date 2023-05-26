#include "sys_headers.h"

/**
 * __getline - custom getline to accept input from the
 * standard input stream
 * @lineptr: pointer to the line to be retrieved from standard input
 * @n: current size of the buffer
 * @stream: standard stream from which input is to be read
 *
 * Return: Returns the number of lines read on success
 */

ssize_t __getline(char **lineptr, size_t *n, FILE *stream)
{
	int c;
	size_t i = 0;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);

	if (*lineptr == NULL)
	{
		*n = 128;
		*lineptr = (char *)malloc(*n);

		if (*lineptr == NULL)
			return (-1);
	}

	while ((c = getc(stream)) != EOF)
	{
		if (i >= *n - 1)
		{
			*n *= 2;
			char *new_ptr = (char *)realloc(*lineptr, *n);

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
