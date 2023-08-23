#include "main.h"

/**
 * cd_home - checks for if buffer is NULL to return to home
 * @buffer: the commands
*/
void cd_home(char **buffer)
{
	char *path;
	int temp;

	if (buffer[1] == NULL)
	{
		path = _getenv("HOME");
		temp = _cd(path);
	}
	else
		temp = _cd(buffer[1]);
	if (temp == -1)
		print_builtin_error("cd: can't cd to ", buffer[1]);
}
