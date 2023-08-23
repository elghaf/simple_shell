#include "simple_shell.h"
/**
 * find_command_in_path - Fuctn finds the full path
 * of a comnd in the PATH envirnmnt
 * @command: Comnd to search for
 *
 * Fuctn search for full path of given comnd by checking directories
 * Return: Full path (On success), NULL (Not found)
 */
char *find_command_in_path(const char *command)
{
char *path, *path_copy, *dir, *command_path;

if (command[0] == '/')
{
if (access(command, X_OK) == 0)
{
return (strdup(command));
}
else
{
return (NULL);
}
}
path = getenv("PATH");
path_copy = strdup(path);
dir = strtok(path_copy, ":");
command_path = NULL;
while (dir != NULL)
{
command_path = malloc(strlen(dir) + strlen(command) + 2);
if (command_path == NULL)
{
perror("allocation error");
exit(EXIT_FAILURE);
}
sprintf(command_path, "%s/%s", dir, command);
if (access(command_path, X_OK) == 0)
{
free(path_copy);
return (command_path);
}
free(command_path);
dir = strtok(NULL, ":");
}
free(path_copy);
return (NULL);
}
