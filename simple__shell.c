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
int buffer_size = TOKEN_BUFSIZE;
int position = 0;
char **parsed_tokens = malloc(buffer_size * sizeof(char *));
char *parsed_token;

if (!parsed_tokens)
{
fprintf(stderr, "allocation error\n");
exit(EXIT_FAILURE);
}

parsed_token = strtok(input_line, TOKEN_DELIMITERS);
while (parsed_token != NULL)
{
parsed_tokens[position] = parsed_token;
position++;

if (position >= buffer_size)
{
buffer_size += TOKEN_BUFSIZE;
parsed_tokens = realloc(parsed_tokens, buffer_size * sizeof(char *));
if (!parsed_tokens)
{
fprintf(stderr, "perror\n");
exit(EXIT_FAILURE);
}
}
parsed_token = strtok(NULL, TOKEN_DELIMITERS);
}
parsed_tokens[position] = NULL;
return parsed_tokens;
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
