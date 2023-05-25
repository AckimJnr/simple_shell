#include "sys_headers.h"
#define ER_MSG "%s: %d: %s: not found\n"
/**
 * exec_path - execute function from path
 * @args: program arguments
 * @s_count: session counter
 * @pg_name: name of program
 *
 * Return: void;
 */
void exec_path(char *args[], int s_count, char *pg_name)
{
	char *path = getenv("PATH");
	char *token;
	char *cmd_path = NULL;
	int status;
	pid_t pid;
	int command_found = 0;

	token = strtok(path, ":");
	if (path == NULL)
	{
		perror(pg_name);
		exit(EXIT_FAILURE);
	}
	while (token != NULL)
	{
		size_t path_len = strlen(token) + strlen(args[0]) + 2;

		cmd_path = malloc(path_len);
		snprintf(cmd_path, path_len, "%s/%s", token, args[0]);


		if (access(cmd_path, X_OK) == 0)
		{
			command_found = 1;
			break;
		}
		free(cmd_path);
		cmd_path = NULL;
		token = strtok(NULL, ":");
	}
	if (!command_found)
	{
		fprintf(stderr, ER_MSG, pg_name, s_count, args[0]);
		exit(EXIT_FAILURE);
	}
	pid = fork();

	if (pid < 0)
	{
		perror(pg_name);
		return;
	}
	else if (pid == 0)
	{
		if (execv(cmd_path, args) < 0)
		{
			fprintf(stderr, ER_MSG, pg_name, s_count, args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	free(cmd_path);
}
