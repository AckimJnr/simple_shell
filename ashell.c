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
	ssize_t bytes_read;
	size_t buffer_size = 0;

	while (1)
	{
		printf("$ ");
		bytes_read = getline(&command, &buffer_size, stdin);
		if (bytes_read == -1)
		{
			putchar('\n');
			exit(EXIT_FAILURE);
		}
		else if (bytes_read == 1)
		{
			putchar('\n');
			break;
		}
		else if (command[bytes_read - 1] == '\n')
			command[bytes_read - 1] = '\0';

		execute_command(command);
	}
	free(command);
	return (0);
}
