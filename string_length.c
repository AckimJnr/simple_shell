#include "sys_headers.h"
/**
 * string_length - prints a string to the std out
 * @str: string to be printed
 *
 * Return: Returns size of string
 */

size_t string_length(const char *str)
{
	size_t string_len = 0;
	const char *str_ptr = str;

	while (*str_ptr != '\0')
	{
		string_len++;
		str_ptr++;
	}

	return (string_len);
}
