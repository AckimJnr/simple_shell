#include "sys_headers.h"

/**
 * exec_path - execute function from path
 * @args: program arguments
 * @s_count: session counter
 * @pg_name: name of program
 * @pid: process id
 * @status: exit_status
 * @path: path of the program to be executed
 *
 * Return: void;
 */
void _path(char *args[], char *path
		, int s_count, char *pg_name, int pid, int *status)
{
	if (pid < 0)
	{
		perror(pg_name);
		return;
	}
	else if (pid == 0)
	{
		if (execv(path, args) < 0)
		{
			fprintf(stderr, ER_MSG, pg_name, s_count, args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
		waitpid(pid, status, 0);
}
