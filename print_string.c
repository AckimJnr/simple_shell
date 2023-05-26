#include "sys_headers.h"
/**
 * print_string - prints a string to the std out
 * @str: string to be printed
 *
 * Return: Returns void
 */

void print_string(const char *str)
{
	size_t string_len = 0;
	const char *str_ptr = str;
	ssize_t bytes_written = 0;

	while (*str_ptr != '\0')
	{
		string_len++;
		str_ptr++;
	}

	bytes_written = write(STDOUT_FILENO, str, string_len);

	if (bytes_written == -1)
		exit(EXIT_FAILURE);
}
