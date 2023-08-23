#include "main.h"
/**
 * tokenize - intitializes argv
 * @buf: input string from the user
 *
 * Return: argv (array of arguments)
 */
char **tokenize(char *buf)
{
	char *buf_cpy, *tkn, *del = " \n";
	char **argv;
	int num_tkns = 0, i;

	buf_cpy = strdup(buf);
	if (buf_cpy == NULL)
	{
		perror("Memory allocation error");
	}
	tkn = strtok(buf, del);
	num_tkns++;
	while (tkn != NULL)
	{
		tkn = strtok(NULL, del);
		num_tkns++;
	}
	argv = malloc(num_tkns * sizeof(char *));
	tkn = strtok(buf_cpy, del);
	for (i = 0; tkn != NULL; i++)
	{
		argv[i] = strdup(tkn);
		tkn = strtok(NULL, del);
	}
	argv[i] = NULL;
	free(buf_cpy);
	return (argv);
}
