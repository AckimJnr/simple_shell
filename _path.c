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
	pid_t pid;

	pid = fork();

	if (pid < 0)
	{
		perror(pg_name);
		return;
	}
	else if (pid == 0)
	{
		if (execvp(path, args) < 0)
		{
			fprintf(stderr, ER_MSG, pg_name, s_count, args[0]);
			return;
		}
	}
	else
		waitpid(pid, status, 0);
}
