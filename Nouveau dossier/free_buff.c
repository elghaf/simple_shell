#include "main.h"

/**
* free_buff - frees the memory allocated to buffer
* @buffer: the buffer
* @buff_size: the size of the buffer
*/

void free_buff(char **buffer, int buff_size)
{
	int i;

	for (i = 0; i < buff_size; i++)
	{
		free(buffer[i]);
	}
	free(buffer);
}
