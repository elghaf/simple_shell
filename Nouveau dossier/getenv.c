#include "main.h"

/**
 * _getenv - this function gets the value of an environment variable
 * @name: the name of environment variable
 * Return: returns NULL if failed, pointer to value
*/
char *_getenv(char *name)
{
	int i;

	i = 0;
	while (__environ[i] != NULL)
	{
		if (strncmp(__environ[i], name, strlen(name)) == 0)
			return (&__environ[i][strlen(name) + 1]);
		i++;
	}
	return (NULL);
}
