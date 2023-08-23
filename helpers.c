#include "main.h"

/**
 * _strcmp - compare strings
 * @s1: first string to be checked
 * @s2: second string to be checked
 * Return: 0 true if strings match, 1 if false
 */

int _strcmp(char *s1, char *s2)
{
	int i, counter1 = 0, counter2 = 0, diff_success = 0;

	for (i = 0; s1[i] != '\0'; i++)
	{
		counter1++;
	}

	for (i = 0; s2[i] != '\0'; i++)
	{
		counter2++;
	}

	for (i = 0; i < counter1 || i < counter2; i++)
	{
		if (s1[i] == s2[i])
		{
			diff_success = 0;
		}
		else
		{
			diff_success++;
			return (s1[i] - s2[i]);
		}
	}
	return (diff_success);
}

/**
 * _strcpy - function copy string from one pointer to another
 * @dest: pointer to recieve string copy.
 * @src: pointer that hold original string copy.
 * Return: string
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0' ; i++)
	{
		dest[i] = src[i];
	}

	dest[i++] = '\0';
	return (dest);
}

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

/**
 * _strncpy - copy chars from src to dest
 * @dest: destination var will recieve string
 * @src: source var to send string
 * @n: max count of chars to be sent
 * Return: char pointer.
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	for (; i < n; i++)
	{
		dest[i] = '\0';
	}
	return (dest);
}

/**
 * _strlen - calculate length of a string
 * @s: variable to be checked
 * Return: length of the string
 */

int _strlen(char *s)
{
	int i, counter = 0;

	for (i = 0; *(s + i) != '\0'; i++)
	{
		counter++;
	}
	return (counter);
}
