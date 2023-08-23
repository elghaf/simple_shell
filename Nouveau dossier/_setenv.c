#include "main.h"

/**
* _setenv - sets an environment variable in format "name=value"
* @name: the name of variable
* @value: the value to set name to
* Return: returns void
*/

int _setenv(char *name, char *value)
{
	int i;
	size_t nameLen, valueLen;

	if (name == NULL)
	{
		custom_error("Error: cannot set name and value");
		return (-1);
	}
	nameLen = strlen(name);
	valueLen = strlen(value);
	for (i = 0; __environ[i] != NULL; i++)
	{
		if (strncmp(__environ[i], name, strlen(name)) == 0)
		{
			free(__environ[i]);
			__environ[i] = malloc(nameLen + valueLen);
			if (__environ[i] == NULL)
			{
				custom_error("Error: cannot set name and value");
				return (-1);
			}
			task(name, value, i);
			return (0);
		}
	}
	free(__environ[i]);
	__environ[i] = malloc(nameLen + valueLen + 2);
	if (__environ[i] == NULL)
	{
		custom_error("Error: cannot set name and value");
		return (-1);
	}
	task(name, value, i);
	__environ[i + 1] = NULL;
	return (0);
}

/**
 * task - sets the variable properly
 * @name: the name of variable
 * @value: the value to set name to
 * @num: the index
*/

void task(char *name, char *value, int num)
{
	strcpy(__environ[num], name);
	strcat(__environ[num], "=");
	strcat(__environ[num], value);
}
