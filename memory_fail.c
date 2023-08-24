#include "main.h"

/**
 * memory_fail - function to free memory if NULL created.
 * @memory: var malloced.
 * Return: -1 for fail
 */

int memory_fail(char *memory)
{
	if (memory == NULL)
	{
		perror("Error in allocating memory");
		return (-1);
	}
	else
	{
		return (0);
	}
}
