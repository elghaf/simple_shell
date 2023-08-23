#include "shell.h"

/**
 * parse_line - Parse a line into an array of arguments (tokens).
 * @line: The line to parse.
 *
 * Return: An array of arguments (tokens), or NULL on failure.
 */
char **parse_line(char *line)
{
	char **tokens;
	char *token;
	unsigned int bufsize = TOK_BUFSIZE;
	int position = 0;

	tokens = malloc(sizeof(char *) * bufsize);

	if (tokens == NULL)
		return (NULL);

	token = strtok(line, TOK_DELIMITERS);

	while (token != NULL)
	{
		tokens[position] = _strdup(token);

		if (tokens[position] == NULL)
			return (NULL);

		position++;

		if (position >= bufsize)
		{
			bufsize += TOK_BUFSIZE;
			tokens = _realloc(tokens, bufsize * sizeof(char *));
		}

		token = strtok(NULL, TOK_DELIMITERS);
	}

	tokens[position] = NULL;
	return (tokens);
}
