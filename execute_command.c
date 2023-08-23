#include "simple_shell.h"
/**
 * execute_command_with_path - This Fuctn execute a comnd
 * using its full path
 * @args: Arr of strs containing the comnd and its args.
 * Fuctn attempts to execute the specified command using its full path
 *
 * Return: 1 (On success), 0 (command not found)
 */
int execute_command_with_path(char **args) {
    pid_t pid;
    int status;

    char *command_path = find_command_in_path(args[0]);
    if (command_path == NULL) {
        return 0; 
    }

    if (access(command_path, X_OK) == -1) {
        perror("simple_shell");
        free(command_path);
        return 0;
    }

    pid = fork();
    if (pid == 0) {
        if (execvp(command_path, args) == -1) {
            perror("simple_shell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("simple_shell");
    } else {
        wait(&status);
    }

    free(command_path);
    return 1;
}

