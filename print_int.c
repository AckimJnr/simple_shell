#include "sys_headers.h"
/**
 * print_integer- prints an integer
 * @number: number to be printed
 *
 * Return: number
 */
void print_integer(int number)
{
	char buffer[20];
	char digits[10];
	int length = 0;
	int i;
	int digitCount = 0;
	int temp = number;

	if (temp == 0)
	{
		buffer[length++] = '0';
	}
	else
	{
		if (temp < 0)
		{
			buffer[length++] = '-';
			temp = -temp;
		}


		while (temp > 0)
		{
			digits[digitCount++] = '0' + (temp % 10);
			temp /= 10;
		}
		for (i = digitCount - 1; i >= 0; i--)
		{
			buffer[length++] = digits[i];
		}
	}
	if (write(STDOUT_FILENO, buffer, length) == -1)
		exit(EXIT_FAILURE);
}
