#include "main.h"

/**
 * get_path - function to find path
 * @filename: cmd.
 * Return: file with path
 */

char *get_path(char *filename)
{
	char *path, *pathCopy, *pathToken, *filePath;
	int cmdLen, dirLen;
	struct stat buffer;

	path = getenv("PATH");

	if (path)
	{
		pathCopy = strdup(path);
		cmdLen = strlen(filename);

		pathToken = strtok(pathCopy, ":");

		while (pathToken != NULL)
		{
			dirLen = strlen(pathToken);
			filePath = malloc(cmdLen + dirLen + 2);
			strcpy(filePath, pathToken);
			strcat(filePath, "/");
			strcat(filePath, filename);
			strcat(filePath, "\0");

			if (stat(filePath, &buffer) == 0)
			{
				free(pathCopy);
				return (filePath);
			}
			else
			{
				free(filePath);
				pathToken = strtok(NULL, ":");
			}
		}
		free(pathCopy);

		if (stat(filename, &buffer) == 0)
		{
			return (filename);
		}
		return (NULL);
	}
	return (NULL);
}
