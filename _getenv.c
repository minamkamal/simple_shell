#include "main.h"

/**
 * _getenv - function to get environment var
 * @name: name of the var to check
 * Return: environment var
 */

char *_getenv(const char *name)
{
	char *env;
	int i;
	size_t name_length = strlen(name);

	if (name == NULL)
	{
		return (NULL);
	}

	for (i = 0; environ[i] != NULL; i++)
	{
		env = environ[i];
		if (_strncmp(env, name, name_length) == 1 && env[name_length] == '=')
		{
			if (env[name_length + 1] != '\0')
			{
				return (&env[name_length + 1]);
			}
			else
			{
				return (NULL);
			}
		}
	}
	return (NULL);
}
