#include "simple_shell.h"
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>


/**
 * display_function - Display the printf $
 */
void display_function(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "#cisfun$ ", 2);
	}
}

/**
 * read_user_input - Read input user input
 *
 * Return: the string
 */
char *read_user_input()
{
char *strings_to_read = NULL;
size_t bufsizes = 0;

getline(&strings_to_read, &bufsizes, stdin);
return (strings_to_read);
}

/**
 * print_user_resutl - display user token.
 * @input_line: The input line.
 *
 * Return: tokens array.
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
position = position + 1;

if (position >= bufsize)
{
bufsize = bufsize + TOKEN_BUFSIZE;
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
 * run_command - Run the command.
 * @arguments: Arguments arrays
 *
 * Return: 1 on success, -1.
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
