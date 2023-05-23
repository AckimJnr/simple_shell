#include "sys_headers.h"
/**
 * built_infunction - executes commands that are local to the shell
 * @args: arguments passed to the program
 * @argc: number of arguments passed
 * @session_counter: tracks number of commands that have been executed by shell
 *
 * Return: Returns 1 if the command is built in our shell or 0 it it is not
 */

int built_infunction(int argc, char *args[], int session_counter)
{
	int status = 0;

	if (string_compare(args[0], "exit") == 0)
	{
		if (argc > 1)
		{
			status = string_toint(args[1]);
			if (status < 0)
			{
				printf("sh: %d: exit: Illegal number: %s\n", session_counter, args[1]);
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
