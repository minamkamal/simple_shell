#include "main.h"

/**
 * main - Entry point for the shell
 * Return: 0 on success
 */
int main(void)
{
	char *user_prompt = "$ ";
	char *lineptr = NULL, **str_arr;
	size_t n = 0;
	ssize_t read_input;

	if (isatty(STDIN_FILENO))
	{
		printf("%s", user_prompt);
		fflush(stdout);
	}
	while ((read_input = getline(&lineptr, &n, stdin)) != -1)
	{
		if (read_input <= 1)
		{
			if (isatty(STDIN_FILENO))
			{
				printf("%s", user_prompt);
				fflush(stdout);
			}
			continue;
		}
		else if (strcmp(lineptr, "exit\n") == 0)
		{
			printf("\n");
			break;
		}
		str_arr = tokenize_input(lineptr);
		exec_cmd(str_arr);
		free_tokens(str_arr);
		if (isatty(STDIN_FILENO))
		{
			printf("%s", user_prompt);
			fflush(stdout);
		}
	}
	free(lineptr);
	return (0);
}
