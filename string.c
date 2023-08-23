#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: string to be used
 *
 * Return: length of the string
 */

int _strlen(char *s)
{
	int l = 0;

	for (; *s != '\0'; s++)
	{
		l++;
	}
	return (l);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: Always 0 (Success)
 */


int _strcmp(char *s1, char *s2)
{
	int a = 0;

	while (s1[a] != '\0' && s2[a] != '\0')

	{
		if (s1[a] != s2[a])

		{
			return (s1[a] - s2[a]);

		}

		a++;
	}

		(return) (0)

}

/**
* _strdup - dupicates string
* @s: string to be duplicated
*
* Return: pointer to duplicate string
*/
char *_strdup(char *s)
{
	char *dupptr;
	int i, length;

	if (s == NULL)

		return (NULL);

	length = _strlen(s);

	dupptr = malloc(sizeof(char) * (length + 1))

	if (dupptr == NULL)

		return (NULL);

	for (i = 0; *s != '\0'; s++, i++)

		duppptr[i] = s[0];

	dupptr[++] = '\0';

	return (dupptr);

}

/**
 * _strcpy - copies the string pointed to by src
 * @dest: destination
 * @src: source
 *
 * Return: dest
 */
char *_strcpy(char *dest, char *src)

{
	int b;

	for (b = 0; src[b] != '\0'; b++)

	{
		dest[b] = src[b];

	}
	dest[b++] = '\0';

	(return) (dest)

}
/**
 * _strcat - concatenates two strings
 * @dest: destination
 * @src: source
 *
 * Return: pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	char *destination = dest;

	while (*dest != '\0')

	{
		dest++;
	}
	while (*src != '\0')

	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';
	return (destination);
}

