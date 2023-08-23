#include "main.h"

/**
 * main - Entry point
 * @ac: argument count
 * @av: array of strings
 *
 * Return: 0 if success -1 otherwise
 */
int main(int ac, char **av)
{
	char *prompt = "$ ", *lineptr = NULL;
	char **command;
	size_t len = 0;
	ssize_t num_chars;
	const char *delim = " \n";
	(void)ac, (void)av;

	while (1)
	{
		print_prompt(prompt);
		num_chars = getline(&lineptr, &len, stdin);
		if (num_chars == -1)
			return (-1);
		lineptr[num_chars - 1] = '\0';
		command = tokenizeLine(lineptr, delim);
		if (command == NULL || *command == NULL || **command == '\0')
		{
			free(lineptr);
			continue;
		}
		if (exit_command(command[0]))
			break;

		if (_strcmp(command[0], "env") == 0)
		{
			print_env();
		}
		else
		{
			execute_command(command);
		}
	}
	free(lineptr);
	return (0);
}
