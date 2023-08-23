#include "shell.h"

/**
 * main - Entry point of the shell.
 *
 * Return: Always 0.
 */
int main(void)
{
    char *line;
    char **args;
    int status;

    do {
        printf("YourShell> ");
        line = get_line(); // Implement get_line function to read a line of input
        args = tokenize(line); // Implement tokenize function to tokenize the input line
        status = execute(args); // Implement execute function to execute the command
        free(line);
        free(args);
    } while (status);

    return (0);
}
