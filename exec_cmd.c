#include "main.h"

/**
 * exec_cmd - function to execute cmd and fork process.
 * @str_arr: user command
 * Return: status
 */

void exec_cmd(char **str_arr)
{
	char *cmd = NULL;
	char *finalCmd = NULL;
	int status;
	pid_t pid;

	if (str_arr)
	{
		cmd = str_arr[0];
		finalCmd = get_path(cmd);

		if (finalCmd != NULL)
		{
			pid = fork();
			if (pid == -1)
				perror("fork error");
			else if (pid == 0)
			{
				if (execve(finalCmd, str_arr, NULL) == -1)
					perror("execve error");
				exit(1);
			}
			else
			{
				wait(&status);
			}
		}
		else
		{
			printf("bash: %s: not found\n", cmd);
		}
	}
}
