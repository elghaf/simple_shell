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
 * read_input - Read input from the user
 *
 * Return: The input line read from the user
 */
char *read_input()
{
char *strings = NULL;
size_t bufsizes = 0;

getline(&strings, &bufsizes, stdin);
return (strings);
}

/**
 * parse_input - Parse user input into tokens
 * @input_line: The input line
 *
 * Return: An array of tokens
 */
char **parse_input(char *input_line)
{
int bufsize = TOKEN_BUFSIZE;
int position = 0;
char **tokens;
char *token;

tokens = malloc(bufsize * sizeof(char *));
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
 * execute - Execute a command
 * @args: An array of arguments
 *
 * Return: 1 on success, -1 on failure
 */
int execute(char **args)
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
