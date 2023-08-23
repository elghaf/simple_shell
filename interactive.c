#include "simple_shell.h"
/**
 * handle_interactive - This is entry point of simple shell program
 *
 * Fuctn handles interactive mode
 *
 * Return: EXIT_SUCCESS (Always)
 */

void handle_interactive(void)
{
char *input;
char **args;
int interactive = isatty(STDIN_FILENO);

while (interactive)
{
printf("shell$ ");
fflush(stdout);
input = read_input();

if (input == NULL)
{
exit(EXIT_SUCCESS);
}

args = parse_input(input);

if (args[0] != NULL)
{
if (execute_builtin(args) == 0)
{
if (!execute_command_with_path(args))
{
fprintf(stderr, "Command not found: %s\n", args[0]);
}
}
}
else
{
fprintf(stderr, "Command not found: %s\n", input);
}
}
}
