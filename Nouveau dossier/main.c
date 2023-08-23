#include "main.h"

static char *FIRSTARG;

/**
* main -Entry point
* @arg: number of argument
* @av: array of arguments
* Return: always 0
*/

int main(int arg, char **av)
{
	ssize_t get;
	size_t buff_size;
	int exec_file, fd;
	char *buffer = NULL;

	FIRSTARG = av[0];
	buff_size = 0;
	exec_file = 0;
	fd = checkargs(arg, av);
	while (1)
	{
		if (isatty(STDIN_FILENO) == 1 && exec_file == 0)
			write(STDOUT_FILENO, "$ ", 2);
		/*Get STDIN from STDIN*/
		get = getline(&buffer, &buff_size, stdin);
		if (get == EOF)
		{
			free(buffer);
			return (0);
		}
		buffer = handle_comment(buffer);
		_strtok(buffer, "\n");
		brkdown_args(buffer);
	}
	free(buffer);
	if (exec_file)
		close(fd);
	return (0);
}

/**
 * get_first_av - Returns the first argument passed to main
 *
 * Return: Pointer to first arg passed to main
*/
char *get_first_av(void)
{
	return (FIRSTARG);
}
