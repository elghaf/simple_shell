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
int main()
{
int i = 0;
char *line;
char **args;

while (1)
{
print_prompt();
line = read_input();
args = parse_input(line);
execute(args);
// Free the memory allocated for the parsed arguments
for (i = 0; args[i] != NULL; i++)
{
free(args[i]);
}
free(args);
free(line);
}
return (0);
}

