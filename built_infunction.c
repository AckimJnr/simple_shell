#include "sys_headers.h"
#define ERR "%s: %d: exit: Illegal number: %s\n"
/**
 * built_infunction - executes commands that are local to the shell
 * @args: arguments passed to the program
 * @argc: number of arguments passed
 * @s_counter: tracks number of commands that have been executed by shell
 * @pg_name: program name
 *
 * Return: Returns 1 if the command is built in our shell or 0 it it is not
 */
int built_infunction(int argc, char *args[], int s_counter, char *pg_name)
{
	int status = 0;

	if (string_compare(args[0], "exit") == 0)
	{
		if (argc > 1)
		{
			status = atoi(args[1]);
			if (status < 0)
			{
				fprintf(stderr, ERR, pg_name, s_counter, args[0]);
				return (1);
			}
			exit_program(status);
		}
		exit_program(status);
	}

	else if (string_compare(args[0], "env") == 0)
	{
		print_env();
		return (1);
	}
	return (0);
}
