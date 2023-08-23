#include "main.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - main program
 * Return: 0 on success
 */

int main(void)
{
	char *token;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	pid_t cmd_pid;
	int status;
	char *cmd;
	int val;
	int argc;
	char *argv[MAX_ARGS];

	printf("$ ");
	fflush(stdout);

	while (1)
	{
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			printf("\n");
			return (-1);
		}
		token = strtok(line, " \t\n");

		argc = 0;
		while (token != NULL && argc < MAX_ARGS - 1)
		{
			argv[argc++] = token;
			token = strtok(NULL, " \t\n");
		}
		argv[argc] = NULL;

		if (argc > 0)
		{
			cmd_pid = fork();
			if (cmd_pid == -1)
			{
				perror("Fork Error\n");
				return (1);
			}
			if (cmd_pid == 0)
			{
				cmd = my_which(argv[0]);
				if (cmd)
				{
					val = execve(cmd, argv, NULL);

					if (val == -1)
					{
						perror("Execve Error\n");
						exit(1);
					}
				}
				val = execve(argv[0], argv, NULL);

				if (val == -1)
				{
					perror("Execve Error\n");
					exit(1);
				}
			}
			else
			{
				wait(&status);
			}
		}
		printf("$ ");
		fflush(stdout);
	}
	free(line);
	return (0);
}
