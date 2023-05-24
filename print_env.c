#include "sys_headers.h"
/**
 * print_env - prints the current program's environmental variables
 * and their values
 *
 * Return: Returns void
 */

void print_env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
