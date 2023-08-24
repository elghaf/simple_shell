#include "simple_shell.h"
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

/* Define TOEKN BUFER SIZE */
#define TOKEN_BUFSIZE 64
#define TOKEN_DELIMITERS " \t\r\n\a"



/**
 * display_function - Display the printf $
 */
void display_function(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
}

/**
 * read_user_input - Read input user command
 *
 * Return: The input user line
 */
char *read_user_input()
{
char *strings = NULL;
size_t bufsizes = 0;

getline(&strings, &bufsizes, stdin);
return (strings);
}

/**
 * print_user_resutl - Print user input to token
 * @input_line: The input line
 *
 * Return: Array of tokens in return
 */
char **print_user_resutl(char *input_line)
{
int bufsize = TOKEN_BUFSIZE;
int position = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token;


if (!tokens)
{
fprintf(stderr, "allocation error\n");
exit(EXIT_FAILURE);
}

token = strtok(input_line, TOKEN_DELIMITERS);
while (token != NULL)
{
tokens[position] = token;
position++;

if (position >= bufsize)
{
bufsize += TOKEN_BUFSIZE;
tokens = realloc(tokens, bufsize *sizeof(char *));
if (!tokens)
{
fprintf(stderr, "allocation error\n");
exit(EXIT_FAILURE);
}
}

token = strtok(NULL, TOKEN_DELIMITERS);
}
tokens[position] = NULL;
return (tokens);
}

/**
 * run_specific_command - Execute a command
 * @arguments: An array of arguments
 *
 * Return: 1 on success, -1 on failure
 */
int run_specific_command(char **arguments)
{
pid_t pid;
int pid_status;

pid = fork();
if (pid == 0)
{
if (execvp(arguments[0], arguments) == -1)
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
waitpid(pid, &pid_status, WUNTRACED);
}
return (1);
}




/**
 * handle_builtin_commands - Check and execute builtin commands.
 * @args: An array of strings representing the command and its arguments.
 *
 * Return: 0 if a builtin command was executed, 1 otherwise.
 */
int handle_builtin_commands(char **args)
{
if (strcmp(args[0], "exit") == 0)
{
return (0);
}
else if (strcmp(args[0], "setenv") == 0)
{
return (1);
}
else if (strcmp(args[0], "unsetenv") == 0)
{
return (1);
}
return (1);
}

/**
 * execute_builtin_or_default - Execute a built-in
 * command or a default command.
 * @args: An array of strings representing the
 * command and its arguments.
 *
 * Return: 1 to continue the shell loop if a built-in command is
 * executed, 0 otherwise.
 */
int execute_builtin_or_default(char **args)
{
if (handle_builtin_commands(args) == 0)
{
return (1);
}
else
{
fprintf(stderr, "shell: command not found: %s\n", args[0]);
return (0);
}
}

/**
 * execute_command - Execute a command with its arguments.
 * @args: An array of strings representing the command and
 * its arguments.
 *
 * Return: 1 to continue the shell loop if a command is executed,
 * 0 if the command is "exit".
 */
int execute_command(char **args)
{
if (access(args[0], X_OK) == 0)
{
return (run_specific_command(args));
}
else if (strcmp(args[0], "exit") == 0)
{
return (0);
}
else
{
return (execute_builtin_or_default(args));
}
}

