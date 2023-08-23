#include "shell.h"

/**
 * executor - excute commands
 *
 * @args: string of arguments
 * @path: the path to the command
 *
 * Return: 1 if success 0 if fails
 */

int executor(const char *path, char **args)
{
	pid_t pid = 0;
	int err = 0;

	if (path != NULL)
	{
		pid = fork();
	}
	if (pid  == -1)
	{
		perror("Fork failed");
		return (-1);
	} else if (pid == 0)
	{
		err = execvp(path, args);
		if (err == -1)
		{
			perror("Execvp failed");
			return (-1);
		}
	}

	waitpid(pid, NULL, 0);
	return (1);
}

/**
 * execute_external_command -  fucntion that execute command external
 *
 * @path: the path to the command
 * @cmd: comand line
 * @args: string of arguments
 *
 * Return: 1 if success 0 if fails
 */

int execute_external_command(char *path, char *cmd, char **args)
{
	int worked = 1;

	if (path == NULL)
	{
		printf("not a valid command or path\n");
		free_args(args);
		free(cmd);
		worked = 0;
	} else
	{
		executor(path, args);
	}
	return (worked);
}


/**
 * execute_builtin_commands - excute built-in commands
 *
 * @args: string of arguments
 *
 * Return: 1 if success 0 if fails
 */

int execute_builtin_commands(char **args)
{
	int built_in = 0;

	if (strcmp(args[0], "exit") == 0)
	{
		__exit(args);
		built_in = 1;
	} else if (strcmp(args[0], "setenv") == 0)
	{
		built_in = _setenv(args);
	} else if (strcmp(args[0], "env") == 0)
	{
		built_in = _env(args[0]);
	} else if (strcmp(args[0], "unsetenv") == 0)
	{
		built_in = _unsetenv(args);
	} else if (strcmp(args[0], "cd") == 0)
	{
		built_in = _cd(*args);
	}
	return (built_in);
}

