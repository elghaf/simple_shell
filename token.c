#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * tokenize_string - tokenizes a string into an array of words
 * @input_str: pointer to the input string that you want to tokenize
 * @delimiter: pointer to a constant character string that
 * specifies the delimiter characters
 *
 * Return: array of strings (tokens) that were extracted
 * from the input string
 */

char **tokenize_string(char *input_str, const char *delimiter)
{
    char **tokens = NULL;
    char *str_copy, *token;
    int i, token_count = 0;

    str_copy = strdup(input_str);
    if (str_copy == NULL)
    {
        free(str_copy);
        perror("tsh: memory allocation error");
        return NULL;
    }

    token = strtok(input_str, delimiter);

    while (token != NULL)
    {
        token_count++;
        token = strtok(NULL, delimiter);
    }
    token_count++;

    tokens = malloc(sizeof(char *) * token_count);

    token = strtok(str_copy, delimiter);

    for (i = 0; token != NULL; i++)
    {
        tokens[i] = malloc(sizeof(char) * (strlen(token) + 1));
        strcpy(tokens[i], token);
        token = strtok(NULL, delimiter);
    }
    tokens[i] = NULL;

    free(str_copy);
    return tokens;
}

