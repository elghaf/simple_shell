#include "main.h"

/**
* environ - prints all environment variables
*/
void environ(void)
{
	int i;

	i = 0;
	while (__environ[i] != NULL)
	{
		write(STDOUT_FILENO, __environ[i], strlen(__environ[i]));
		putchar('\n');
		i++;
	}
}
