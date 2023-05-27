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
	static char buffer[BUF_SIZE];
	static size_t buf_pos;
	static size_t buf_sz;
	ssize_t bytes_read = 0;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);

	if (*lineptr == NULL)
	{
		*n = 128;
		*lineptr = (char *)malloc(*n);

		if (*lineptr == NULL)
			return (-1);
	}
	bytes_read = read_chars(lineptr, n, buffer, &buf_pos, &buf_sz, stream);
	return (bytes_read);
}
