#include "main.h"

/**
 * main - start of shell
 * Return: 0 on success
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	pid_t cmd_pid;
	int status;
	char *argv[MAX_ARGS];
	int argc = 0;
	char *token;
	char *cmd;
	int val;

	printf("$ ");
	fflush(stdout);

	while ((read = my_getline(&line, &len, stdin)) != -1)
	{
		if (read == 0)
		{
			printf("\n");
			break;
		}

		argc = 0;
		token = strtok(line, " \t\n");

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
						return (1);
					}
				}
				else
				{
					val = execve(argv[0], argv, NULL);
					if (val == -1)
					{
						perror("Execve Error\n");
						return (1);
					}
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
