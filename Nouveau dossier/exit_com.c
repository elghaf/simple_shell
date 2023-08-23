#include "main.h"

/**
* exit_com - handles exit commands
* @buffer: the array of arguments
* @buff_size: the size of the buffer
* Return: 0 if successful, 1 if failed
*/
int exit_com(char **buffer, int buff_size)
{
	if (strcmp(*buffer, "exit") == 0 || *buffer == NULL)
	{
		free_buff(buffer, buff_size);
		exit(0);
	}
	else
		return (1);
}
