#include "main.h"

/**
 * _shell_command_checks - A function used to shell commands then run
 * specific functions
 * @args: a pointer to a pointer of shell command arguements.
 * @size: size ot first @args arguements.
 * @av: a pointer to a pointer to all arguements passsed to the program.
 * @env: a pointer to a pointer to environment variables.
 *
 * Return: char *.
 */
char *_shell_command_checks(char *const *args,
ssize_t size, char **av, char **env)
{
	char *new_arg = NULL;

	if ((args[0][0] == 'e') && (args[0][1] == 'n') && (args[0][2] == 'v'))
	{
		_env(env);
	}
	else if ((args[0][0] == 'e') && (args[0][1] == 'x') &&
		(args[0][2] == 'i') && (args[0][3] == 't'))
	{
		_exit_(args, av, size, env);
	}
	else if ((args[0][0] == '.') && (args[0][1] == '/'))
	{
		new_arg = malloc((sizeof(char) * strlen(args[0])) + 1);
		if (new_arg == NULL)
			return (NULL);
		strcat(new_arg, args[0]);
	}
	else if ((args[0][0] != '/') && (args[0][1] != 'b')
		&& (args[0][2] != 'i') && (args[0][3] != 'n')
		&& (args[0][4] != '/'))
		new_arg = _add_bin_to_new_arg(args);
	else
	{
		new_arg = malloc((sizeof(char) * strlen(args[0])) + 1);
		if (new_arg == NULL)
			return (NULL);
		strcat(new_arg, args[0]);
	}
	return (new_arg);
}
