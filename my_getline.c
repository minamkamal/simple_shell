#include "main.h"

/**
 * my_getline - reading from stdin
 * @lineptr: buffer to store the chars.
 * @n: count.
 * @stream: standard input stream to read from.
 * Return: count of chars.
 */

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	char ch;
	size_t size = *n;
	size_t i = 0;
	char *newPtr;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);

	if (*lineptr == NULL)
	{
		*lineptr = (char *)malloc(size);
		if (*lineptr == NULL)
			return (-1);
	}

	while ((ch = fgetc(stream)) != EOF)
	{
		if (i >= size - 1)
		{
			size *= 2;
			newPtr = (char *)realloc(*lineptr, size);
			if (newPtr == NULL)
			{
				free(*lineptr);
				return (-1);
			}
			*lineptr = newPtr;
			*n = size;
		}
		(*lineptr)[i++] = ch;
		if (ch == '\n')
		{
			break;
		}
	}

	if (i == 0)
	{
		return (-1);
	}
	(*lineptr)[i] = '\0';
	return (i);
}
