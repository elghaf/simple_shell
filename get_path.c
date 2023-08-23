#include "shell.h"

/**
 *getpath - Searches for full path of command in system's PATH dirs.
 * @cmd: The command name to search for
 *
 * Return: Full path to command, or NULL if not found or memory error.
 */
char *getpath(char *cmd)
{
	const char *path = getenv("PATH");
	char *pathcpy = strdup(path);
	char *direct = _strtok(pathcpy, ":");

	if (cmd[0] == '/')
	{
		if (access(cmd, F_OK) == 0)
			return (strdup(cmd));
		else
			return (NULL);
	}

	while (direct != NULL)
	{
		char fpath[1024];

		snprintf(fpath, sizeof(fpath), "%s/%s", direct, cmd);

		if (access(fpath, F_OK) == 0)
		{
			free(pathcpy);
			return (strdup(fpath));
		}
		direct = _strtok(NULL, ":");
	}
	free(pathcpy);
	return (NULL);
}
