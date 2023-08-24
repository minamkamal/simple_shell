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
	size_t i = 0;

	if (!lineptr || !n || !stream)
		return (-1);

	if (!*lineptr && !(*lineptr = malloc(*n)))
		return (-1);

	while ((ch = fgetc(stream)) != EOF)
	{
		if (i >= *n - 1 && !(*lineptr = realloc(*lineptr, (*n *= 2))))
			return (-1);
		(*lineptr)[i++] = ch;
		if (ch == '\n')
			break;
	}

	if (!i)
		return (-1);
	(*lineptr)[i] = '\0';
	return (i);
}
