#include "main.h"

/**
 * _env - A function to print the current OS environment variables.
 * @env: a pointer to a pointer to the OS environment variables.
 *
 * Return: void.
 */
void _env(char **env)
{
	int i = 0;

	while (env[i] != NULL)
	{
		dprintf(STDOUT_FILENO, "%s\n", env[i]);
		++i;
	}
}
