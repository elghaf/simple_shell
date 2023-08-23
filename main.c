#include "simple_shell.h"
/**
 * main - This is entry point of simple shell program
 *
 * Fuctn implemnts the main loop of the shell
 *
 * Return: EXIT_SUCCESS (Always)
 */
int main(void)
{
int interactive = isatty(STDIN_FILENO);

if (!interactive)
{
handle_non_interactive();
return (EXIT_SUCCESS);
}

handle_interactive();

return (EXIT_SUCCESS);
}

