#include "simple_shell.h"

/**
 * print_environment - Fuctn prints all envirmnt variabls and their valus.
 *
 * Fuctn iterates through the envirmnt variabls, prints the variable
 */

void print_environment(void)
{
char **env = __environ;
while (*env)
{
if (*env)
{
char *var = strtok(*env, "=");
char *value = strtok(NULL, "=");
printf("%s=%s\n", var, value);
}
env++;
}
}

