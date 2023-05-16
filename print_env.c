#include "sys_headers.h"
/**
 * print_env - prints the current program's environmental variables
 * and their values
 *
 * Return: Returns void
 */

void print_env(void)
{
	char **env = NULL;

	for (env = environ; *env != NULL; env++)
	{
		print_string(*env);
		print_string("\n");
	}
}
