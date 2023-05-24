#include "sys_headers.h"

/**
 * print_error- prints error messages to standard output
 * @session_counter: number of times a command is executed
 * @args: contains program name
 *
 * Return: void
 */
void print_error(int session_counter, char *args[], char *program_name)
{
	/** print_string("sh: ");*/
	print_string(program_name);
	print_string(" ");
	print_integer(session_counter);
	print_string(": ");
	print_string(args[0]);
	print_string(": ");
	print_string("not found\n");
}
