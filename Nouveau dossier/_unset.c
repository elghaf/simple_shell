#include "main.h"

/**
* unset - unsets an environment variable
* @name: the name of environment variable to set
* Return: returns -1 if failed, 0 for success
*/

int unset(char *name)
{
	int i, j;

	if (name == NULL)
	{
		custom_error("Error: cannot set name and value");
		return (-1);
	}
	i = 0;
	while (__environ[i] != NULL)
	{
		if (strncmp(__environ[i], name, strlen(name)) == 0)
		{
			free(__environ[i]);
			for (j = i; __environ[j] != NULL; j++)
				__environ[j] = __environ[j + 1];
		}
		i++;
	}
	__environ[i] = __environ[i + 1];
	return (0);
}
