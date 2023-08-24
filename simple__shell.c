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
 * print_environment - Print environment variables
 */
void print_environment(void)
{
extern char **environ; // This is an array of strings containing the environment variables
int i = 0;

for (i = 0; environ[i] != NULL; i++)
{
printf("%s\n", environ[i]);
}
}

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
 * run_command - Execute a command
 * @arguments: An array of arguments
 *
 * Return: 1 on success, -1 on failure
 */
int run_command(char **arguments)
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
