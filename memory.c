#include "shell.h"

/**
 * _strdup - Duplicate a string.
 * @str: The string to duplicate.
 *
 * Return: A pointer to the newly allocated string, or NULL if allocation fails.
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int i, len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len])
		len++;

	dup = malloc(sizeof(char) * (len + 1));

	if (dup == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		dup[i] = str[i];

	return (dup);
}

/**
 * _free - Free an array of pointers.
 * @arr: The array to free.
 */
void _free(char **arr)
{
	unsigned int i;

	if (arr == NULL)
		return;

	for (i = 0; arr[i] != NULL; i++)
	{
		free(arr[i]);
	}

	free(arr);
}
