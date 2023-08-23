#include "shell.h"

/**
 * sig_handler - Handles the SIGINT signal (Ctrl+C)
 * @sig_num: The signal number received
 */
void sig_handler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		_puts("\n#cisfun$ ");
	}
}

/**
 * _EOF - Handles the End of File scenario
 * @len: The return value of the getline function
 * @buff: The input buffer
 */
void _EOF(int len, char *buff)
{
	(void)buff;
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n"); /* Print newline if Ctrl+D is pressed*/
			free(buff);
		}
		exit(0);
	}
}

/**
 * _isatty - Checks if the program is running in a terminal
 */
void _isatty(void)
{
	if (isatty(STDIN_FILENO))
		_puts("##cisfun$ ");
}

/**
 * main - Entry point for the shell program
 * Return: 0 on success
 */
int main(void)
{
	ssize_t length = 0;
	char *buffer = NULL, *value, *pathname, **args;
	size_t size = 0;
	list_path *head = '\0';
	void (*f)(char **);

	signal(SIGINT, sig_handler);
	while (length != EOF)
	{
		_isatty();
		length = getline(&buffer, &size, stdin);
		_EOF(length, buffer);
		args = splitstring(buffer, " \n");
		if (!args || !args[0])
			execute(args);
		else
		{
			value = _getenv("PATH"); /* Get environment variable*/
			head = linkpath(value); /* Create path list*/
			pathname = _which(args[0], head); /* Find executable path*/
			f = checkbuild(args); /* Check for built-in command*/
			if (f)
			{
				free(buffer);
				f(args);
			}
			else if (!pathname)
				execute(args);
			else if (pathname)
			{
				free(args[0]);
				args[0] = pathname;
				execute(args); /* Execute command with updated path*/
			}
		}
	}
	free_list(head); /* Free path list memory*/
	freearv(args); /* Free tokenized input memory*/
	free(buffer); /* Free input buffer memory*/
	return (0);
}
