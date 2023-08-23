#include "main.h"

/**
 * print_env - prints the current environment
 *
 * Return: void
 */

void print_env(void)
{
	char **env_var = environ;

	while (*env_var != NULL)
	{
	write(STDOUT_FILENO, *env_var, strlen(*env_var));
	write(STDOUT_FILENO, "\n", 1);
	env_var++;
	}
}

