#include "main.h"

/**
 * _getline - A function used to read a single line from the stdin.
 * @args: modified arguements passed to the program.
 * @semi_seen: a variable used to check if a semi column was seen.
 *
 * Return: ssize_t.
 */
ssize_t _getline(char *const **args, int **semi_seen)
{
	ssize_t len = 0, i = 0, x = 0;
	int arr_size = 1, seen = 0;
	char buffer[999999], c;
	char **argv;

	while (read(STDIN_FILENO, &c, 1) > 0)
	{
		if ((c != '\t') && (c != '\v') && (c != '\r'))
		{
			buffer[x] = c;
			len = len + 1;
			if (buffer[x] == '\n')
			{
				buffer[x] = '\0';
				break;
			}
			++x;
		}
		if (c == ';')
		{
			**semi_seen = 1;
			break;
		}
	}
	len = _getline_len_check(len, buffer);
	for (i = 0; i < len; ++i)
	{
		if (((seen < 1) && ((buffer[i] >= 'a') && (buffer[i] <= 'z')))
			|| ((buffer[i] >= 'A') && (buffer[i] <= 'Z')))
			++seen;
		if (buffer[i] == ' ')
			++arr_size;
	}
	argv = _getline_processor(args, len, buffer, arr_size);
	if (argv == NULL)
		return (-1);
	*args = *(&argv);
	return (len);
}
