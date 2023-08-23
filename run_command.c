#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * execute - Execute a command
 * @args: An array of arguments
 *
 * Return: 1 on success, -1 on failure
 */

int run_command(char **args)
{
pid_t pid;
int status;

pid = fork();
if (pid == 0)
{
if (execvp(args[0], args) == -1)
{
perror("execvp error");
}
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
perror("fork error");
}
else
{
waitpid(pid, &status, WUNTRACED);
}
return (1);
}
