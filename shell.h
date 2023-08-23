#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_INPUT 1024

void execute_command(char *command) {
    char *args[100];  // Maximum number of arguments
    int i = 0;

    // Tokenize the input command
    char *token = strtok(command, " ");
    while (token != NULL) {
        args[i] = token;
        token = strtok(NULL, " ");
        i++;
    }
    args[i] = NULL;  // Null-terminate the argument list

    // Fork a child process
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("shell");
        }
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        // Parent process
        wait(NULL);
    } else {
        perror("shell");
    }
}

int main(int argc, char *argv[]) {
    char input[MAX_INPUT];

    if (argc > 1) {
        // File mode - Read commands from a file
        FILE *file = fopen(argv[1], "r");
        if (file == NULL) {
            perror("shell");
            exit(EXIT_FAILURE);
        }

        while (fgets(input, sizeof(input), file) != NULL) {
            // Remove trailing newline character
            input[strcspn(input, "\n")] = '\0';
            execute_command(input);
        }

        fclose(file);
    } else {
        // Interactive mode - Read commands from the user
        while (1) {
            printf("shell$ ");
            fflush(stdout);

            if (fgets(input, sizeof(input), stdin) == NULL) {
                break;  // End of input (Ctrl+D)
            }

            // Remove trailing newline character
            input[strcspn(input, "\n")] = '\0';

            if (strcmp(input, "exit") == 0) {
                break;  // Exit the shell
            }

            execute_command(input);
        }
    }

    return 0;
}
