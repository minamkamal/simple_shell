#include "main.h"

/**
 * tokenize_input - Tokenize input string
 * @input: Input string
 * Return: Array of strings
 */
char **tokenize_input(char *input)
{
    int token_count = 0, i;
    char *token, *input_copy;
    char **str_arr;

    input_copy = strdup(input);
    if (input_copy == NULL)
    {
        perror("strdup");
        exit(EXIT_FAILURE);
    }

    token = strtok(input_copy, " \n");
    while (token != NULL)
    {
        token_count += 1;
        token = strtok(NULL, " \n");
    }

    str_arr = malloc((token_count + 1) * sizeof(char *));
    if (str_arr == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    token = strtok(input, " \n");
    for (i = 0; token != NULL; i++)
    {
        str_arr[i] = strdup(token);
        if (str_arr[i] == NULL)
        {
            perror("strdup");
            exit(EXIT_FAILURE);
        }
        token = strtok(NULL, " \n");
    }
    str_arr[i] = NULL;

    free(input_copy);
    return str_arr;
}
