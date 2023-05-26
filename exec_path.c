#include "sys_headers.h"
/**
 * exec_path - execute function from path
 * @args: program arguments
 * @s_count: session counter
 * @pg_name: name of program
 * @status: exit status
 *
 * Return: void;
 */
int exec_path(char *args[], int s_count, char *pg_name, int *status)
{
	char *path = getenv("PATH");
	char *token;
	char *cmd_path = NULL;
	int command_found = 0;

	(void) status;
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
	/** _path(args, cmd_path, s_count, pg_name, status); */
	execv(cmd_path, args);
	free(cmd_path);
	return (1);
}
