#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point of the simple shell program
 * @argc: The argument count
 * @argv: The argument vector
 *
 * Description:
 * Entry point for program the simple shell.
 * It operates by repeatedly displaying the shell prompt,
 * reading user input, parsing the input,
 * and executing the parsed command along with its arguments.
 *
 * Return:
 * Always returns 0.
 */
int main(int argc, char **argv)
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
