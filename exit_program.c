#include "sys_headers.h"

/**
 * exit_program-exits the shell
 * @status: exit status for a program
 *
 * Return: no return value
 */
void exit_program(int status)
{
	signal(SIGTERM, SIG_IGN);
	kill(getpid(), SIGTERM);
	exit(status);
}
