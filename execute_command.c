#include "sys_headers.h"
/**
 * execute_command - executes a given command
 * @command: command to be executed
 *
 * Description: This function will execute a command
 * by attempting to execute a programm at the dir given
 * Return: Returns nothing
 */
void execute_command(char *command)
{
	char *args[ARGS_LIMIT];
	int argc = 0, exit_status;
	pid_t pid;

	/* split the command to get the program path */
	char *token = strtok(command, " \t\n");

	while (token != NULL && argc < ARGS_LIMIT - 1)
	{
		args[argc] = token;
		argc++;
		token = strtok(NULL, " \t\n");
	}

	args[argc] = NULL;

	pid = fork();

	if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		execve(args[0], args, NULL);
		perror("./ashell");
		exit(1);
	}
	else
		waitpid(pid, &exit_status, 0);
}
