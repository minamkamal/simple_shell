#include "main.h"

/**
 * get_path - function to find path
 * @filename: cmd.
 * Return: file with path
 */

char *get_path(char *filename)
{
	char *path = getenv("PATH");
	char *pathCopy, *pathToken, *filePath;
	int cmdLen = strlen(filename);
	struct stat buffer;

	if (path == NULL)
		return (NULL);
	pathCopy = strdup(path);
	if (pathCopy == NULL)
		return (NULL);
	pathToken = strtok(pathCopy, ":");

	while (pathToken != NULL)
	{
		size_t dirLen = strlen(pathToken);

		filePath = malloc(dirLen + cmdLen + 2);
		if (filePath == NULL)
		{
			free(pathCopy);
			return (NULL);
		}
		strcpy(filePath, pathToken);
		strcat(filePath, "/");
		strcat(filePath, filename);
		if (stat(filePath, &buffer) == 0)
		{
			free(pathCopy);
			return (filePath);
		}
		free(filePath);
		pathToken = strtok(NULL, ":");
	}
	free(pathCopy);
	if (stat(filename, &buffer) == 0)
	{
		return (strdup(filename));
	}
	return (NULL);
}
