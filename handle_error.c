#include "main.h"

/**
 * print_builtin_error - Prints error for buitin function
 * @msg: Error message
 * @arg: Argument passed to builtin
*/
void print_builtin_error(char *msg, char *arg)
{
	int len = strlen(msg);
	char *first_av = get_first_av();

	write(STDERR_FILENO, first_av, strlen(first_av));
	write(STDERR_FILENO, ": 1: ", 5);
	write(STDERR_FILENO, msg, len);
	write(STDERR_FILENO, arg, strlen(arg));
	write(STDERR_FILENO, "\n", 1);
}

/**
 * custom_error - writes error message to stderr
 * @msg: the message
*/
void custom_error(char *msg)
{
	int len = strlen(msg);

	write(STDERR_FILENO, msg, len);
}
