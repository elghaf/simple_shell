#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point of the simple shell program
 *
 * This function serves as the entry point for the simple shell.
 * It repeatedly prints the shell prompt, reads input, parses the input,
 * and executes the parsed arguments as a command.
 *
 * Return: Always returns 0.
 */
int main(void)
{
int i = 1;
char *text_line;
char **args;

while (i)
{
print_prompt();
text_line = read_input();
args = parse_input(text_line);
execute(args);
free(text_line);
free(args);
}

return (0);
}
