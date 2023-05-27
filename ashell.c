#include "sys_headers.h"
/**
 * main - program start point
 * @argc: number of arguments passed
 * @argv: arguments passed
 *
 * Description: this is the starting point of the ashell,
 * It receives program invocations and arguments
 * and executes the requested for program and its arguments
 * Return: Returns 0 on successful execution
 */
int main(int argc, char *argv[])
{
	char *command = NULL;
	ssize_t bytes_read = 0;
	size_t buffer_size = 0;
	static int session_counter = 1;
	int ispiped = 0;

	(void) argc;
	(void) argv;
	--session_counter;
	if (!isatty(STDIN_FILENO))
		ispiped = 1;

	if (!ispiped)
		print_string("$ ");

	while ((bytes_read = __getline
				(&command, &buffer_size, stdin)) != EOF)
	{
		if (bytes_read == 1)
		{
			if (!ispiped)
				session_counter++;
		}
		else
		{
			if (command[bytes_read - 1] == '\n')
				command[bytes_read - 1] = '\0';

			execute_command(command, session_counter, argv[0]);
			session_counter++;
		}
		if (!ispiped)
			print_string("$ ");
	}
	if (bytes_read <= 0 && !ispiped)
		putchar('\n');
	free(command);
	return (0);
}
