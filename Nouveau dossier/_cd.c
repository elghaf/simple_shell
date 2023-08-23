#include "main.h"

/**
* _cd - changes a directory of file
* @path: the buffer
* Return: return 0 in success, -1 for failure
*/

int _cd(char *path)
{
	char temp[1024];

	getcwd(temp, 1024);
	if (strcmp(path, "-") == 0)
	{
		char *oldpwd = _getenv("OLDPWD");

		if (oldpwd != NULL)
			return (chdir(oldpwd));
		_setenv("OLDPWD", temp);
		chdir("..");
		_setenv("OLDPWD", _getenv("PWD"));
		return (0);
	}
	if (chdir(path) == -1)
		return (-1);
	return (0);
}
