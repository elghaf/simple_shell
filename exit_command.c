#include "main.h"

/**
 * exit_command-handles exit command and exits the shell
 * @command: pointer to a character string that represents a command
 * to be checked
 * Return:int
 */
int exit_command(char *command)
{
	return (_strcmp(command, "exit") == 0);

}

