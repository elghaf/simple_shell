#include "shell.h"

int main(void)
{
    char *line;
    char **args;
    int status;

    do
    {
        printf("$ "); // Display a simple prompt
        line = read_line(); // Implement your read_line function
        args = split_line(line); // Implement your split_line function
        status = execute(args); // Implement your execute function

        free(line);
        free(args);
    } while (status);

    return EXIT_SUCCESS;
}
