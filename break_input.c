#include "main.h"

/**
* brkdown_args - splits arguments with _strtok()
* @buffer: the array of arguments
* Return: 0 if failed
*/

int brkdown_args(char *buffer)
{
	char *temp;
	char **args;
	int i;

	args = malloc(sizeof(char *) * (strlen(buffer) + 1));
	if (args == NULL)
	{
		perror("Memory allocation failed");
		return (0);
	}
	temp = strdup(buffer);
	if (temp == NULL)
	{
		perror("Memory allocation failed");
		free(args);
		return (0);
	}
	i = 0;
	temp = _strtok(buffer, " ");
	while (temp != NULL)
	{
		args[i] = strdup(temp);
		temp = _strtok(NULL, " ");
		i++;
	}
	free(temp);
	execute_file(args, i);
	free_buff(args, i);
	return (1);
}
