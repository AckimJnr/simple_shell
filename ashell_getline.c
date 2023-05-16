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
	size_t buffer_size = *buf_size;
	size_t bytes_read = 0;
	size_t char_number = 0;
	char input_character;
	char *readline = NULL;

	if (line_ptr == NULL || buf_size == NULL || fd < 0)
		return (-1);

	if (*line_ptr == NULL)
	{
		buffer_size = 128;
		*line_ptr = malloc(buffer_size);

		if (*line_ptr == NULL)
			return (-1);
	}

	while ((bytes_read = read(fd, &input_character, STDOUT_FILENO)) > 0)
	{
		if (char_number >= buffer_size - 1)
		{
			buffer_size *= 2;
			readline = realloc(*line_ptr, buffer_size);
			if (readline == NULL)
				return (-1);
			*line_ptr = readline;
		}
		(*line_ptr)[char_number++] = input_character;

		if (input_character == '\n')
			break;

	}

	(*line_ptr)[char_number++] = '\0';

	if (char_number == 0 && bytes_read <= 0)
		return (-1);

	*buf_size = buffer_size;

	return (char_number);
}
