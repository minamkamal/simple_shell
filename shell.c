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

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("%s", user_prompt);
			fflush(stdout);
		}
		read_input = getline(&lineptr, &n, stdin);
		if (read_input <= 1)
		{
			continue;
		} else if (strcmp(lineptr, "exit\n") == 0)
		{
			printf("\n");
			break;
		}
		str_arr = tokenize_input(lineptr);
		if (str_arr == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				printf("%s", user_prompt);
				fflush(stdout);
			}
			continue;
		}
		exec_cmd(str_arr);
		free_tokens(str_arr);
	}
	free(lineptr);
	return (0);
}
