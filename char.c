#include "shell.h"

/**
 * _strdup - Returns a pointer to a newly allocated space in memory, containing
 *           a copy of the string pointed to by @src.
 * @src: Pointer to the source string
 * Return: Pointer to a newly allocated string
*/
char *_strdup(char *src)
{
	int j, length;
	char *new_str;

	if (!src)
	{
		return (NULL);
	}
	for (length = 0; src[length] != '\0';)
	{
		length++;
	}
	new_str = malloc(sizeof(char) * length + 1);
	if (!new_str)
	{
		return (NULL);
	}
	for (j = 0; j < length; j++)
	{
		new_str[j] = src[j];
	}
	new_str[length] = src[length];
	return (new_str);
}

/**
 * concat_all - Concatenates three strings into a newly allocated memory space
 * @str1: First string
 * @str2: Second string
 * @str3: Third string
 * Return: Pointer to the new concatenated string
*/

char *concat_all(char *str1, char *str2, char *str3)
{
	char *result;
	int len1, len2, len3, j, m;

	len1 = _strlen(str1);
	len2 = _strlen(str2);
	len3 = _strlen(str3);

	result = malloc(len1 + len2 + len3 + 1);
	if (!result)
	{
		return (NULL);
	}

	for (j = 0; str1[j]; j++)
		result[j] = str1[j];
	m = j;

	for (j = 0; str2[j]; j++)
		result[m + j] = str2[j];
	m = m + j;

	for (j = 0; str3[j]; j++)
		result[m + j] = str3[j];
	m = m + j;

	result[m] = '\0';

	return (result);
}

/**
 * _strlen - Calculates the length of a string
 * @str: Pointer to the string
 * Return: Length of string
*/
int _strlen(char *str)
{
	int i = 0;

	while (*(str + i) != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - Prints a string
 * @str: Pointer to string
*/
void _puts(char *str)
{
	int j;

	for (j = 0; str[j]; j++)
	{
		_putchar(str[j]);
	}
}
