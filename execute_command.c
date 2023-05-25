#include "sys_headers.h"
/**
 * execute_command - executes a given command
 * @command: command to be executed
 * @session_counter: number of commands executed
 * @program_name: name of the porgram used
 *
 * Description: This function will execute a command
 * by attempting to execute a programm at the dir given
 * Return: Returns nothing
 */
void execute_command(char *command, int session_counter, char *program_name)
{
	char *args[ARGS_LIMIT];
	int argc = 0, exit_status;
	pid_t pid;

	/* split the command to get the program path */
	char *token = strtok(command, " \t\n");

	session_counter++;
	while (token != NULL && argc < ARGS_LIMIT - 1)
	{
		args[argc] = token;
		argc++;
		token = strtok(NULL, " \t\n");
	}

	if (built_infunction(argc, args, session_counter, program_name, &exit_status))
		return;

	args[argc] = NULL;
	
	pid = fork();
	
	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		
		execve(args[0], args, NULL);
		print_error(session_counter, args, program_name);
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, &exit_status, 0);
}
