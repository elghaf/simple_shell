#include "main.h"

/**
 * execute_command - executes a command with arguments
 * @av: double pointer to an array of strings
 *
 * Return: void
 */

void execute_command(char **av)
{
	char *command = NULL, *ac = NULL;
	pid_t child_pid;
	int status;

	if (av)
	{
		command = av[0];

		ac = get_path(command);

		if (ac == NULL)
		{
			perror(command);
			return;
		}

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
		}
		else if (child_pid == 0)
		{
			if (execve(ac, av, NULL) == -1)
			{
				perror(command);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(child_pid, &status, 0);
		}
	}
}
