#include <ctype.h>
#include <limits.h>
#include "sys_headers.h"
/**
 * string_toint- converts a string to an interger
 * @str: string to be converted
 *
 * Return: the converted digit
 */
int string_toint(char *str)
{
	int i, number = 0;

	for (i = 0; str[i] >= '0' && str[i] <= '9'; ++i)
		number = 10 * number + (str[i] - '0');

	return (number);
}
