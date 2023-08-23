#include "main.h"

/**
 * _fork - A function used to determine if a child process should be
 * created in the terminal.
 * @ter_str: command prompt to be displayed.
 * @argv: a modified array of pointers of arguments.
 * @new_arg: the shell command to be execute.
 * @av: the original array of pointers of arguments.
 * @calls: arguement number.
 * @env: a pointer to a pointer to the OS environment variables.
 * @semi_seen: a variable to check if a semi column was seen.
 *
 * Return: void.
 */
void _fork(char *ter_str, char *const *argv, char *new_arg,
char **av, int calls, char **env, int **semi_seen)
{
	pid_t cid;
	int status;

	if (access(new_arg, F_OK) == 0)
	{
		cid = fork();
		if (cid == 0)
		{
			execve(new_arg, argv, env);
		}
		else
		{
			waitpid(cid, &status, 0);
			if (status == 512)
			{
				_shell(0, av, env, **semi_seen);
				exit(2);
			}
			else
			{
				_shell(0, av, env, **semi_seen);
				exit(0);
			}
			if ((isatty(STDIN_FILENO) == 1) && (**semi_seen != 1))
				dprintf(STDOUT_FILENO, "%s", ter_str);
			if (**semi_seen == 1)
				**semi_seen = 0;
		}
	}
	else
	{
		dprintf(STDERR_FILENO, "%s: %d: %s: not found\n",  av[0], calls, new_arg);
		_shell(0, av, env, **semi_seen);
		exit(127);
		if (isatty(STDIN_FILENO) == 1)
			dprintf(STDOUT_FILENO, "%s", ter_str);
	}
}
