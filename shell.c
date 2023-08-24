#include "main.h"

/**
 * main - start of shell
 * Return: 0 on success
 */

int main(void)
{
	char *user_prompt = "($) ";
	char *lineptr = NULL, *lineptrCopy = NULL;
	const char *delimiter = " \n";
	size_t n = 0;
	ssize_t read_input;
	int token_count = 0;
	char *token;
	char **str_arr;
	int i;

	while (1)
	{
		printf("%s", user_prompt);
		read_input = my_getline(&lineptr, &n, stdin);
		if (read_input == -1)
		{
			printf("\n");
			break;
		}

		lineptrCopy = malloc(read_input * sizeof(char));
		if (lineptrCopy == NULL)
		{
			perror("Error in allocating memory");
				return(-1);
		}

		strcpy(lineptrCopy, lineptr);

		token = strtok(lineptr, delimiter);
		while (token != NULL)
		{
			token_count += 1;
			token = strtok(NULL, delimiter);
		}
		token_count += 1;

		str_arr = malloc(token_count * sizeof(char *));
		if (str_arr == NULL)
		{
			perror("Error in allocating memory for str_arr");
			return(-1);
		}

		token = strtok(lineptrCopy, delimiter);
		for (i = 0; token != NULL; i++)
		{
			str_arr[i] = malloc(strlen(token) * sizeof(char *));
			if (str_arr[i] == NULL)
			{
				perror("Error in allocating memory slot for strings");
				return(-1);
			}
			strcpy(str_arr[i], token);

			token = strtok(NULL, delimiter);
		}
		str_arr[i] = NULL;

		exec_cmd(str_arr);
	}	
	free(lineptrCopy);
	free(lineptr);
	return (0);
}
