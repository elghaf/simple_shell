#include "main.h"

/**
 * main - program entry point.
 * @ac: number of arguements passed to the program through
 * the terminal.
 * @av: an array of pointers to the arguements passed to the
 * program.
 * @env: a pointer to a pointer to the OS environment variables.
 *
 * Return: int.
 */
int main(int ac, char **av, char **env)
{
	_shell(ac, av, env, 0);
	return (0);
}

/**
 * _shell - A function used to start a simple shell.
 * @ac: number of arguements passed to the program.
 * @av: an array of pointers to the arguements passed to the program.
 * @env: a pointer to a pointer to the OS environment variables.
 * @semi_seen: a variable used to check if a semi column was seen.
 *
 * Return: void.
 */
void _shell(__attribute__((unused)) int ac, char **av,
char **env, int semi_seen)
{
	ssize_t size = -1;
	char ter_str[] = "#cisfun$ ";
	char *const *argv, *new_arg = NULL;
	int calls = 1, *_semi_seen = &semi_seen, **__semi_seen = &_semi_seen;

	if ((isatty(STDIN_FILENO) == 1) && (semi_seen != 1))
		dprintf(STDOUT_FILENO, "%s", ter_str);
	if (semi_seen == 1)
		semi_seen = 0;

	while ((size = _getline(&argv, __semi_seen)) > 0)
	{
		if (size > 1)
		{
			new_arg = _shell_command_checks(argv, size, av, env);
			if (new_arg != NULL)
			{
				_fork(ter_str, argv, new_arg, av, calls, env, __semi_seen);
				++calls;
			}
			else
			{
				if (isatty(STDIN_FILENO) == 1)
					dprintf(STDOUT_FILENO, "%s", ter_str);
			}
		}
		else if (size == 1)
		{
			if (isatty(STDIN_FILENO) == 1)
				dprintf(STDOUT_FILENO, "%s", ter_str);
		}
	}
	if ((size == -1) && (isatty(STDIN_FILENO) == 1))
		dprintf(STDOUT_FILENO, "\n");
	if (new_arg != NULL)
		free(new_arg);
}
