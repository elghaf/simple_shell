#include "main.h"

/**
* execute_file - executes a program
* @buffer: the buffer
* @buff_size: size of buffer
* Return: returns 0 if failed. 1
*/
int execute_file(char **buffer, int buff_size)
{
	pid_t pid;
	char str[100] = "/bin/";

	pid = fork();
	buffer[buff_size] = NULL;
	if (strncmp(*buffer, str, strlen(str)) == 0)
		strcpy(str, *buffer);
	else
		strcat(str, buffer[0]);
	exit_com(buffer, buff_size);
	if (pid == 0)
		handle_coms(buffer, str);
	else if (pid > 0)
		wait(NULL);
	else
		free_buff(buffer, buff_size);
	return (1);
}
