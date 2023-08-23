#include "main.h"

/**
* handle_coms - checks the first arg of buffer
* @buffer: the buffer
* @str: the command str (/bin/)
*/

void handle_coms(char **buffer, char *str)
{
	if (strncmp(*buffer, "env", 3) == 0)
		environ();
	else if (strncmp(*buffer, "setenv", strlen(*buffer)) == 0)
		_setenv(buffer[1],  buffer[2]);
	else if (strncmp(*buffer, "unsetenv", strlen(*buffer)) == 0)
		unset(buffer[1]);
	else if (strncmp(*buffer, "cd", strlen(*buffer)) == 0)
		cd_home(buffer);
	else
	{
		execve(str, buffer, NULL);
		perror(buffer[0]);
	}
}
