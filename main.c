#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * main - Entry point of the simple shell program
 * @ac: Number of command-line arguments
 * @args: Array of command-line argument strings
 *
 * This function serves as the entry point for the simple shell.
 * It takes command-line arguments, displays the shell prompt,
 * reads user input, parses the input, and executes the parsed arguments as a command.
 *
 * Return: Always returns 0.
 */
int main(int ac, char **args)
{
    int i = 1, j = 1;
    char *line_input;       // Stores user input line
    char **parsed_arguments;  // Stores parsed arguments

    // Check if the program was run with arguments
    //if (ac > 1)
    //{
    //    // Handle arguments passed to the program
    //    for (i = 1; i < ac; i++)
    //    {
    //        printf("Argument %d: %s\n", i, args[i]);
    //    }
    //    return 0;
    //}

    while (j)
    {
        // Display the shell prompt
        display_prompt();

        // Read user input
        line_input = obtainUserInput();

        // Parse the input into individual arguments
        parsed_arguments = tokenizeUserInput(line_input);

        // Execute the parsed arguments as a command
        runCommand(parsed_arguments);

        // Free dynamically allocated memory
        free(parsed_arguments);
        free(line_input);
    }

    return 0;
}
