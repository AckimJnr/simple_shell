/**
 * execute_from_path- Handles path in a shell
 * @cmd_name: command name
 *
 * Return: Path name of the program
 */
char *execute_from_path(char *cmd_name)
{
	char *path = getenv("PATH");
	char *token = strtok(path, ":");


	char *active_path = malloc(FILENAME_MAX);

	if (active_path == NULL)
	{
		perror("malloc");
		exit(1);
	}

	while (token != NULL)
	{
		snprintf(active_path, FILENAME_MAX, "%s%s", token, cmd_name);
		if (access(program_path, X_OK) == 0)
			return (active_path);

		token = strtok(NULL, ":");
	}
	free(active_path);
	return (NULL);
}
