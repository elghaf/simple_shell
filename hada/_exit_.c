#include "main.h"

/**
 * _exit_ - A function used to exit from the shell.
 * @args: modified a pointer to a pointer to all arguements passed to the
 * program.
 * @av: unmodified arguments passed to the program.
 * @size: size of arguement passed to the exit function.
 * @env: a pointer to a pointer to the OS environment variable.
 *
 * Return: void.
 */
void _exit_(char *const *args, char **av, ssize_t size, char **env)
{
	if ((args[1] != NULL) && ((args[1][0] < '0') || args[1][0] > '9'))
	{
		dprintf(STDERR_FILENO, "%s: %d: exit: Illegal number: %s\n",
		av[0], 1, args[1]);
		_shell(0, av, env, 0);
		exit(2);
	}
	if ((args[1] != NULL) && (atoi(args[1]) < 0))
	{
		dprintf(STDERR_FILENO, "%s: %d: exit: Illegal number: %d\n",
		av[0], 1, atoi(args[1]));
		_shell(0, av, env, 0);
		exit(2);
	}
	if (size > 6)
		exit(atoi(args[1]));
	exit(EXIT_SUCCESS);
}
