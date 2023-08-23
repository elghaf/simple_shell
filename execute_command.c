#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * runCommand - Execute a command
 * @arguments: An array of arguments
 *
 * Return: 1 on success, -1 on failure
 */
int runCommand(char **arguments)
{
    pid_t childPid;
    int childStatus;

    childPid = fork();
    if (childPid == 0)
    {
        if (execvp(arguments[0], arguments) == -1)
        {
            perror("execvp error");
        }
        exit(EXIT_FAILURE);
    }
    else if (childPid < 0)
    {
        perror("fork error");
    }
    else
    {
        waitpid(childPid, &childStatus, WUNTRACED);
    }
    return 1;
}
