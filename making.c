#include "shell.h"

/**
 * exitt - exits the program
 * @arv: array of chars.
 */
void exitt(char **arv)
{
	int cpt, nb;

	if (arv[1])
	{
		nb = _atoi(arv[1]);
		if (nb <= -1)
			nb = 2;
		freearv(arv);
		exit(nb);
	}
	for (cpt = 0; arv[cpt]; cpt++)
		free(arv[cpt]);
	free(arv);
	exit(0);
}

/**
 * _atoi - converts a string into an integer
 *@s: adresse to the string
 *Return: integr.
 */
int _atoi(char *s)
{
	int cpt, k, g = 1;

	cpt = 0;
	k = 0;
	while (!((s[cpt] >= '0') && (s[cpt] <= '9')) && (s[cpt] != '\0'))
	{
		if (s[cpt] == '-')
		{
			g = g * (-1);
		}
		cpt++;
	}
	while ((s[cpt] >= '0') && (s[cpt] <= '9'))
	{
		k = (k * 10) + (g * (s[cpt] - '0'));
		cpt++;
	}
	return (k);
}

/**
 * env - prints the current environment
 * @arv: array that has arrgs
 */
void env(char **arv __attribute__ ((unused)))
{

	int cpt;

	for (cpt = 0; environ[cpt]; cpt++)
	{
		_puts(environ[cpt]);
		_puts("\n");
	}

}

/**
 * _setenv - Initialize a new environment variable, or modify an existing one
 * @arv: array of input words.
 */
void _setenv(char **arv)
{
	int cpt, j, k;

	if (!arv[1] || !arv[2])
	{
		perror(_getenv("_"));
		return;
	}

	for (cpt = 0; environ[cpt]; cpt++)
	{
		j = 0;
		if (arv[1][j] == environ[cpt][j])
		{
			while (arv[1][j])
			{
				if (arv[1][j] != environ[cpt][j])
					break;

				j++;
			}
			if (arv[1][j] == '\0')
			{
				k = 0;
				while (arv[2][k])
				{
					environ[cpt][j + 1 + k] = arv[2][k];
					k++;
				}
				environ[cpt][j + 1 + k] = '\0';
				return;
			}
		}
	}
	if (!environ[cpt])
	{

		environ[cpt] = concat_all(arv[1], "=", arv[2]);
		environ[cpt + 1] = '\0';

	}
}

/**
 * _unsetenv - remove env variable
 * @arv: array of input words
 */
void _unsetenv(char **arv)
{
	int cpt, j;

	if (!arv[1])
	{
		perror(_getenv("_"));
		return;
	}
	for (cpt = 0; environ[cpt]; cpt++)
	{
		j = 0;
		if (arv[1][j] == environ[cpt][j])
		{
			while (arv[1][j])
			{
				if (arv[1][j] != environ[cpt][j])
					break;

				j++;
			}
			if (arv[1][j] == '\0')
			{
				free(environ[cpt]);
				environ[cpt] = environ[cpt + 1];
				while (environ[cpt])
				{
					environ[cpt] = environ[cpt + 1];
					cpt++;
				}
				return;
			}
		}
	}
}
