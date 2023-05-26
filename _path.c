#include "sys_headers.h"

/**
 * exec_path - execute function from path
 * @args: program arguments
 * @s_count: session counter
 * @pg_name: name of program
 * @status: exit_status
 * @path: path of the program to be executed
 *
 * Return: void;
 */
void _path(char *args[], char *path
		, int s_count, char *pg_name, int *status)
{
	(void) s_count;
	(void) pg_name;
	(void) status;

	execv(path, args);
}
