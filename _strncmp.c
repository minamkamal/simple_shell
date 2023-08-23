#include "main.h"

/**
 * _strncmp - creation of strncmp function
 * @s1: first var to be checked.
 * @s2: second var to be checked.
 * @n: comare till specific length
 * Return: count of chars found
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;
	int match = 1;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			match = 0;
			break;
		}
	}
	return (match);
}
