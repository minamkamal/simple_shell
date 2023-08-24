#include "main.h"

/**
* get_path - function to find path
* @filename: cmd.
* Return: file with path
*/
char *get_path(char *filename)
{
	char *path = getenv("PATH"),
	     *pathCopy, *pathToken, *filePath;
	int cmdLen = strlen(filename), dirLen;
	struct stat buffer;

	if (path)
	{
		pathCopy = strdup(path);
		pathToken = strtok(pathCopy, ":");

		while (pathToken != NULL)
		{
			dirLen = strlen(pathToken);
			filePath = malloc(cmdLen + dirLen + 2);
			strcpy(filePath, pathToken);
			strcat(filePath, "/");
			strcat(filePath, filename);

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
