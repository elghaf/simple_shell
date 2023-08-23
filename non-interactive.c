#include "simple_shell.h"
/**
 * handle_non_interactive - This is entry point of simple shell program
 *
 * Fuctn handles non-interactive mode
 *
 * Return: EXIT_SUCCESS (Always)
 */

void handle_non_interactive(void)
{
char *input = NULL;
char **args = NULL;

size_t input_size = 0;
ssize_t read = getline(&input, &input_size, stdin);

if (read == -1)
{

exit(EXIT_SUCCESS);
}

if (read > 0 && input[read - 1] == '\n')
input[read - 1] = '\0';

args = parse_input(input);

if (args[0] != NULL)
{
if (execute_builtin(args) == 0)
{
if (!execute_command_with_path(args))
{
fprintf(stderr, "Command not found: %s\n", args[0]);
exit(EXIT_FAILURE);
}
}
}
}

