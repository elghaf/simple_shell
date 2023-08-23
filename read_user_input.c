#include "simple_shell.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * read_input - Read input from the user
 *
 * Return: The input line read from the user
 */
char *read_input()
{
char *line = NULL;
size_t bufsize = 0;

getline(&line, &bufsize, stdin);
return (line);
}
