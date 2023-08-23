#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * main - Entry point of the simple shell program
 *
 * Description: This function serves as the entry point
 * for the simple shell.
 *
 * Return: Always returns 0.
 */
int main(void)
{
    char *line;
    char **args;

    while (1)
    {
        print_prompt();
        line = read_input();
        args = parse_input(line);
        execute(args);
        free(line);
        free(args);
    }

    return (0);
}
