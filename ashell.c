#include "sys_headers.h"
/**
 * main - program start point
 *
 * Description: this is the starting point of the ashell,
 * It receives program invocations and arguments
 * and executes the requested for program and its arguments
 * Return: Returns 0 on successful execution
 */
int main(void)
{
	char *command = NULL;
	ssize_t bytes_read = 0;
	size_t buffer_size = 0;
	static int session_counter = 1;

	print_string("$ ");
	while ((bytes_read = ashell_getline
				(&command, &buffer_size, STDIN_FILENO)) != EOF)
	{
		if (bytes_read == 1)
		{
			putchar('\n');
			break;
		}
		else if (bytes_read == 2)
			session_counter++;
		else
		{
			if (command[bytes_read - 1] == '\n')
				command[bytes_read - 1] = '\0';

			execute_command(command, session_counter++);
		}
		print_string("$ ");
	}
	free(command);:
	return (0);
}
