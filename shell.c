#include "main.h"

/**
* main - start of shell
* Return: 0 on success
*/
int main(void)
{
	char *lineptr = NULL, *lineptrCopy = NULL, **str_arr, *token;
	size_t n = 0;
	ssize_t read_input;
	int token_count = 0, i;

	while (1)
	{
		printf("$");
		read_input = my_getline(&lineptr, &n, stdin);
		if (read_input == -1 || strcmp(lineptr, "exit\n") == 0)
		{
			printf("\n");
			break;
		}
		lineptrCopy = malloc(read_input * sizeof(char));
		memory_fail(lineptrCopy);
		strcpy(lineptrCopy, lineptr);
		token = strtok(lineptr, " \n");
		while (token != NULL)
		{
			token_count += 1;
			token = strtok(NULL, " \n");
		}
		token_count += 1;
		str_arr = malloc(token_count * sizeof(char *));
		token = strtok(lineptrCopy, " \n");
		for (i = 0; token != NULL; i++)
		{
			str_arr[i] = malloc(strlen(token) * sizeof(char *));
			memory_fail(str_arr[i]);
			strcpy(str_arr[i], token);
			token = strtok(NULL, " \n");
		}
		str_arr[i] = NULL;
		exec_cmd(str_arr);
	}
	free(lineptrCopy);
	free(lineptr);
	return (0);
}
