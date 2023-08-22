#include "main.h"
#include <stdio.h>

/**
 * display_prompt - function to display shell prompt
 *
 * Return: no return void
 */

void display_prompt(void) {
    if (isatty(STDIN_FILENO)) {
        printf("($) ");
        fflush(stdout);  // Ensure prompt is displayed immediately
    }
}

/**
 * get_input_line - This function reads a line of input from the user.
 *
 * Return: A pointer to the user's input line.
 */
char *get_input_line(void)
{
    char *input_line = NULL;
    size_t buffer_size = 0;
    ssize_t chars_read;

    chars_read = getline(&input_line, &buffer_size, stdin);
    if (chars_read == -1) {
        free(input_line);
        exit(EXIT_SUCCESS);
    }

    if (input_line == NULL)
        return NULL;

    return input_line;
}
