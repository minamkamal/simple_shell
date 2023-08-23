#include "main.h"

char *_getenv(char *name)
{
	char *env;
	int i;
	size_t name_length;

	if (name == NULL)
	{
		return (NULL);
	}

	name_length = _strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		env = environ[i];

		if (_strncmp(env, name, name_length) == 0 && env[name_length] == '=')
		{
			return (&env[name_length + 1]);
		}
	}
	return (NULL);
}
