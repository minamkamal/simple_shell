#include "main.h"

char **str_split(char *str)
{
        char **wordArr = NULL;
        int start = 0;
        int arrSize = 1;
        int wordCount = 0;
        int strLen = _strlen(str);
        int i;

        for (i = 0; i <= strLen; i++)
        {
                if (isspace(str[i]) || str[i] == '\0')
                {
                        if (i > start)
                        {
                                char *word = (char *)malloc(i - start + 1);
                                if (word == NULL)
                                {
                                        return (NULL);
                                }
                                _strncpy(word, str + start, i - start);
                                word[i - start] = '\0';

                                wordArr = realloc(wordArr, arrSize * sizeof(char *));
                                if (wordArr == NULL)
                                {
                                        return (NULL);
                                }
                                wordArr[wordCount] = word;
                                arrSize++;
                                wordCount++;
                        }
                        start = i + 1;
                }
        }
        return (wordArr);
}