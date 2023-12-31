#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point of the simple shell program.
 *
 * This function is entry point for the simple shell.
 * It loop to prints the shell prompt,
 * reads input, parses the input,
 * executes the parsed arguments as a command.
 *
 * Return: Always returns 0.
 */
int main(void)
{
int i = 1;
char *text_line;
char **pass_argument;

while (i)
{
display_function();
text_line = read_user_input();
pass_argument = print_user_resutl(text_line);
run_command(pass_argument);
free(text_line);
free(pass_argument);
}

return (0);
}
