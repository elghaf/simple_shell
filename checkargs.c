#include "main.h"

/**
* checkargs - this check arguments passed
* @arg: number of args passed
* @ac: array of args
* Return: returns pointer to stdin
*/
int checkargs(int arg, char **ac)
{
	int temp = STDIN_FILENO;
	char *error = "Error: more than one argument\n";

	if (arg > 2)
	{
		write(STDOUT_FILENO, error, strlen(error));
	}
	if (temp == -1)
	{
		perror(ac[0]);
	}
	return (temp);
}
