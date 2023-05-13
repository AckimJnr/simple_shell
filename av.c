#include "sys_headers.h"
/**
 * main-prints all the arguments, without using ac
 * @ac: arguement count
 * @av: arguement vector
 *
 * Return: number of arguements
 */
int main(__attribute__((unused))int ac, char **av)
{
	int i;

	for (i = 1; av[i] != NULL; i++)
	{
		printf("%s\n", av[i]);
	}
	return (0);
}
