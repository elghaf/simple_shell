#include "main.h"
/**
 * builtin - Handles the built-in command to the shell
 * @argv: array of arguments
 * @env: array of environment variables
 * @exit: flag to indicate exit command
 *
 * Return: 0 on exit, status
 */
int builtin(char **argv, char **env, int *exit)
{
	int i = 0, status;

	if (strcmp(argv[0], "exit") == 0)
	{
		printf("Exiting.......\n");
		*exit = 1;
		if (argv[1] != NULL)
		{
			status = atoi(argv[1]);
			return (status);
		}
		else
		{
			return (0);
		}
	}
	if (strcmp(argv[0], "env") == 0)
	{
		while (env[i])
		{
			printf("%s\n", env[i++]);
		}
	}
	return (0);
}
