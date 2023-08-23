#include "shell.h"

/**
 * shell_loop - loop that gets the command and proccess it
 */


void shell_loop(void)
{
	char **args = NULL;
	char  *cmd = NULL;
	char *path = NULL;
	int exit_loop = 0;

	while (!exit_loop)
	{
		printf("isma :)");
		fflush(stdout);
		if (!isatty(STDIN_FILENO))
		{
			exit_loop = 1;
		}
		cmd = getcmd();
		if (cmd == NULL || strlen(cmd) == 0 || strspn(cmd, " \t\n") == strlen(cmd))
		{
			printf("not a valid command \n");
			free(cmd);
			continue;
		}

		args = get_token(cmd, " ");
		if (args[0] == NULL)
		{
			printf("no command entered.\n");
			free_args(args);
			free(cmd);
			continue;
		}

		path = getpath(args[0]);
		execute_external_command(path, cmd, args);
	}
}
