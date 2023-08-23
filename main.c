#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point of the simple shell program
 * @argc: The argument count
 * @argv: The argument vector
 *
 * Description:
 * This is the main function that serves as the entry point for the simple shell program.
 * It operates by repeatedly displaying the shell prompt, reading user input, parsing the input,
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
