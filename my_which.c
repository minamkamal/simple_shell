#include "main.h"

/**
 * my_which - function to find path
 * @filename: cmd.
 * Return: file with path
 */

char *my_which(char *filename)
{
	char *path = getenv("PATH");
	char *token;
	char *filepath;

	if (path == NULL)
	{
		fprintf(stderr, "Unable to get PATH environment variable\n");
		return (NULL);
	}

	token = strtok(path, ":");
	while (token != NULL)
	{
		filepath = (char *)malloc(_strlen(token) + _strlen(filename) + 2);
		if (filepath == NULL)
		{
			perror("Memory allocation error");
			exit(1);
		}

		snprintf(filepath, _strlen(token) + _strlen(filename) + 2,
				"%s/%s", token, filename);

		if (access(filepath, F_OK) == 0)
		{
			return (filepath);
		}
		token = strtok(NULL, ":");
	}
	printf("bash: %s: not found.\n", filename);
	return (NULL);
}
