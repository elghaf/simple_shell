#include "shell.h"

/**
 * get_token - Tokenizes a string into an array of tokens.
 * @cmd: The input string to be tokenized.
 * @delim: The delimiter string used to split the input into tokens.
 *
 * Return: An array of strings containing the tokens, or NULL on failure.
 */

char **get_token(char *cmd, char *delim)
{
	char *token;
	char **args = malloc(MAX_TOKENS * sizeof(char *));
	unsigned int i = 0;

	token = _strtok(cmd, delim);

	while (token != NULL)
	{
		args[i] = token;
		i++;
		if (i >= MAX_TOKENS)
		{
			break;
		}
		token = _strtok(NULL, delim);
	}
	args[i] = NULL;

	return (args);
}

/**
 * free_args - Frees the memory allocated for an array of token strings
 * @args: The array of token strings to be freed
 *
 * return: void
 */

void free_args(char **args)
{
	free(args);
}
