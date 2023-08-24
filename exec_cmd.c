#include "main.h"

/**
 * exec_cmd - function to execute cmd and fork process.
 * @str_arr: user command
 * Return: status
 */

int exec_cmd(char **str_arr)
{
	char *cmd = NULL;
	char *finalCmd = NULL;
	int executionStatus = -1;
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
			{
				perror("fork error");
			}
			else if (pid == 0)
			{
				if (execve(finalCmd, str_arr, NULL) == -1)
				{
					perror("execve error");
				}
				exit(1);
			}
			else
			{
				waitpid(pid, &status, 0);
				if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
				{
					executionStatus = 0;
				}
			}
		}
		else
		{
			printf("bash: %s: not found\n", cmd);
			executionStatus = -1;
		}
	}
	return (executionStatus);
}
