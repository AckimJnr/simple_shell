#include "sys_headers.h"
/**
 * ashell_getline - custom getline to accept input from the
 * standard input stream
 * @line_ptr: pointer to the line to be retrieved from standard input
 * @buf_size: current size of the buffer
 * @fd: standard stream from which input is to be read
 *
 * Return: Returns the number of lines read on success
 */

ssize_t ashell_getline(char **line_ptr, size_t *buf_size, int fd)
{
	if (line_ptr == NULL || buf_size == NULL || fd < 0)
		return (-1);

	if (*line_ptr == NULL)
	{
		*buf_size = 128;
		*line_ptr = malloc(*buf_size);

		if (*line_ptr == NULL)
			return (-1);
	}

	return (read_chars(line_ptr, buf_size, fd));
}
