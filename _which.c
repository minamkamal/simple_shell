#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * my_which - function to find the path of cmd
 * @filename: program to find
 * Return: the path
 */

char *my_which(char *filename)
{
	char *path = _getenv("PATH");
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
		filepath = (char *)malloc(strlen(token) + strlen(filename) + 2);

		if (filepath == NULL)
		{
			perror("Memory allocation error");
			return (NULL);
		}

		if (strchr(filename, '.') == NULL)
		{
			snprintf(filepath, strlen(token) + strlen(filename) + 2,
					"%s/%s", token, filename);
		}
		else
		{
			snprintf(filepath, strlen(token) + strlen(filename) + 1, "%s", filename);
		}

		if (access(filepath, X_OK) == 0)
			return (filepath);
		free(filepath);
		token = strtok(NULL, ":");
	}

	fprintf(stderr, "bash: %s: not found\n", filename);
	exit(1);
	return (NULL);
}
