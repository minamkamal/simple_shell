#include "main.h"

/**
 * free_tokens - Free memory allocated for tokens
 * @tokens: Array of strings
 */
void free_tokens(char **tokens)
{
    for (int i = 0; tokens[i] != NULL; i++)
    {
        free(tokens[i]);
    }
    free(tokens);
}
