#include "simple_shell.h"
/**
 * free_args - This fuctn frees memory allocated for an arr of strs
 * @args: Arr of strs to be freed
 *
 * Fuctn iterates through arr of strs pointd to by 'args'
 *
 */

void free_args(char **args)
{
int i;
for (i = 0; args[i] != NULL; i++)
{
free(args[i]);
}
free(args);
}
