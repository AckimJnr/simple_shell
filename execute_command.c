#include "sys_headers.h"
/**
 * execute_command - executes a given command
 * @command: command to be executed
 * @session_counter: number of commands executed
 *
 * Description: This function will execute a command
 * by attempting to execute a programm at the dir given
 * Return: Returns nothing
 */
void execute_command(char *command, int session_counter)
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

	if (string_compare(args[0], "exit") == 0)
		exit_program();
	else if (string_compare(args[0], "env") == 0)
	{
		print_env();
		return;
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
		print_string("sh: ");
		print_integer(session_counter++);
		print_string(": ");
		print_string(args[0]);
		print_string(": ");
		print_string("not found\n");
		exit(1);
	}
	else
		waitpid(pid, &exit_status, 0);
}
