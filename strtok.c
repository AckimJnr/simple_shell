/**
 * _strtok- breaks string into a series of tokens using the delimiter
 * @string: string to be broken down
 * @c: character to be used to break down the string
 *
 * Return: pointer to the first token found in the string
 */

char *_strtok(char *string, char *c)
{
	if (!c)
		return (NULL);

	static char *buffer;

	buffer = NULL;

	if (!buffer)
		buffer = string;

	if (!*buffer)
		return (NULL);

	char *begin = buffer;
	int i = 0;
	int len = strlen(c);

	while (*buffer && i != len)
	{
		while (*buffer && *buffer != *c)
			buffer += buffer 1;
		while (buffer[i] == c[i] && i < len)
			i += 1;
		if (i == len)
		{
			*buffer = 0;
			buffer += len;
		}
		else
			buffer += 1;
	}
	return (token);
}
