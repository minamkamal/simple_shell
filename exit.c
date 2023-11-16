#include "main.h"

/**
 * exit_shell - Execute a command
 * @args: Array of arguments passed to the function
 *
 * Description: Exits the shell with a specified status.
 */

void exit_shell(char **args)
{
	int status = 0;

	if (args[1] != NULL)
	{
		status = atoi(args[1]);
	}

	printf("%d\n", status);
	exit(status);
}
