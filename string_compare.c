/**
 * string_compare- compares two strings
 * @string_1: input value
 * @string_2: input value
 *
 * Return: 0 if string_1 is equal to string_2,
 * less than 0 if string_1 is less than string_2
 * greater than 0 if string_1 greater than string_2
 */
int string_compare(char *string_1, char *string_2)
{
	int i = 0;

	while (string_1[i] != '\0' && string_2[i] != '\0')
	{
		if (string_1[i] != string_2[i])
		{
			return (string_1[i] - string_2[i]);
		}
		i++;
	}
	return (0);
}
