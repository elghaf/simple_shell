#include "main.h"

/**
 * tokenizeLine - tokenizes a string into an array of words
 * @str: pointer to the input string that you want to tokenize
 * @delim: pointer to a constant character string that
 * specifies the delimiter characters
 *
 * Return: array of strings (tokens) that were extracted
 * from the input string
 */

char **tokenizeLine(char *str, const char *delim)
{
	char **av = NULL;
	char *str_copy, *token;
	int i, token_count = 0;

	str_copy = _strdup(str);
	if (str_copy == NULL)
	{
		free(str_copy);
		perror("tsh: memory allocation error");
		return (NULL);
	}

	token = strtok(str, delim);

	while (token != NULL)
	{
		token_count++;
		token = strtok(NULL, delim);
	}
	token_count++;

	av = malloc(sizeof(char *) * token_count);

	token = strtok(str_copy, delim);

	for (i = 0; token != NULL; i++)
	{
		av[i] = malloc(sizeof(char) * _strlen(token));
		_strcpy(av[i], token);
		token = strtok(NULL, delim);
	}
	av[i] = NULL;

	free(str_copy);
	return (av);
}
