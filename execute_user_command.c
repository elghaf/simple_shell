#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"

/**
 * execute_user_command - executes a user command with arguments
 * @command_tokens: double pointer to an array of strings
 *
 * Return: void
 */

void execute_user_command(char **command_tokens)
{
    char *command = NULL, *path_to_command = NULL;
    pid_t child_pid;
    int status;

    if (command_tokens)
    {
        command = command_tokens[0];

        path_to_command = get_path(command);

        if (path_to_command == NULL)
        {
            perror(command);
            return;
        }

        child_pid = fork();
        if (child_pid == -1)
        {
            perror("Error:");
        }
        else if (child_pid == 0)
        {
            if (execve(path_to_command, command_tokens, NULL) == -1)
            {
                perror(command);
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            waitpid(child_pid, &status, 0);
        }
    }
}

