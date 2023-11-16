#include "main.h"

/**
 * exec_cmd - Execute a command
 * @args: Array of strings representing the command and its arguments
 */
void exec_cmd(char **args)
{
	if (strcmp(args[0], "exit") == 0)
	{
		exit_shell(args);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		print_environment();
	}
	else
	{
		pid_t pid;
		int status;

		pid = fork();
		if (pid == 0)
		{
			if (execvp(args[0], args) == -1)
			{
				perror("./shell");
			}
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
		{
			perror("fork");
		}
		else
		{
			do {
				waitpid(pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	printf("Executing command: %s\n", args[0]);
	}
}
