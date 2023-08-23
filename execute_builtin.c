#include "simple_shell.h"
/**
 * execute_builtin - This fuctn executes available built-in shell commands
 * @args: Arr of strs containing command and its args
 *
 * Fuctn checks if given command matches built-in command
 * Return: 1 (if a built-in command executes), 0 (otherwise)
 */

int execute_builtin(char **args)
{
if (strcmp(args[0], "exit") == 0)
{
printf("Exiting the shell...\n");
exit(EXIT_SUCCESS);
}
else if (strcmp(args[0], "env") == 0)
{
print_environment();
return (1);
}
return (0);
}
