#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#include "main.h"

#define MAX_INPUT_LENGTH 1024


// Function to execute a command in a child process
void execute_command(char *command) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        // Child process
        char *args[] = {command, NULL};  // Arguments for execve

        // Execute the command
        execvp(command, args);

        // Print error if execvp fails
        perror("Execution error");
        exit(1);
    } else if (pid > 0) {
        // Parent process
        waitpid(pid, &status, 0);  // Wait for the child to finish
    } else {
        // Fork failed
        perror("Fork error");
    }
}

int main(void) {
    char input[MAX_INPUT_LENGTH];
    ssize_t input_length;

    while (1) {
        // Display the shell prompt
        display_prompt();

        // Read user input
        input_length = read(STDIN_FILENO, input, MAX_INPUT_LENGTH);

        // Handle EOF (Ctrl+D)
        if (input_length <= 0) {
            if (isatty(STDIN_FILENO)) {
                printf("exit\n");
            }
            break;  // Exit the loop
        }

        // Remove trailing newline
        if (input[input_length - 1] == '\n') {
            input[input_length - 1] = '\0';
        }

        // Skip empty input lines
        if (strlen(input) == 0) {
            continue;  // Skip to the next iteration
        }

        // Execute the command
        execute_command(input);
    }

    return 0;
}
