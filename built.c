#include "shell.h"

/**
* checkbuild - checks if the command is a buildin
* @arv: the array of arguments
* Return: adress to the function.
*/
void(*checkbuild(char **arv))(char **arv)
{
	int cpt, b;
	mybuild T[] = {
		{"exit", exitt},
		{"env", env},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL}
	};

	for (cpt = 0; T[cpt].name; cpt++)
	{
		b = 0;
		if (T[cpt].name[b] == arv[0][b])
		{
			for (b = 0; arv[0][b]; b++)
			{
				if (T[cpt].name[b] != arv[0][b])
					break;
			}
			if (!arv[0][b])
				return (T[cpt].func);
		}
	}
	return (0);
}
