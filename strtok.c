#include "sys_headers.h"
/**
 * _strtok- breaks string into a series of tokens using the delimiter
 * @string: string to be broken down
 * @delimeter: character to be used to break down the string
 *
 * Return: pointer to the first token found in the string
 */

char *_strtok(char *string, char *delimeter)
{
	static char  *generated_token;
	char *token;
	int i, j;

	if (string == NULL && generated_token == NULL)
		return (NULL);

	if (string != NULL)
		generated_token = string;

	token = generated_token;

	for (i = 0; token[i] != '\0'; i++)
	{
		for (j = 0; delimeter[j] != '\0'; j++)
		{
			if (token[i] == delimeter[j])
			{
				token[i] = '\0';
				generated_token = &token[i + 1];
				return (token);
			}
		}
	}
	generated_token = NULL;
	return (token);
}
