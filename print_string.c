#include <unistd.h>

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

	while (*str_ptr != '\0')
	{
		string_len++;
		str_ptr++;
	}

	write(STDOUT_FILENO, str, string_len);
}
