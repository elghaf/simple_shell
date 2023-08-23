#include "main.h"

/**
 * _getline_len_check - a function to check the length
 * of buffer read from the stdout.
 * @len: length of buffer.
 * @buffer: a string of augements passed to the program.
 *
 * Return: ssize_t.
 */
ssize_t _getline_len_check(ssize_t len, char *buffer)
{
	ssize_t i = 0;
	int seen = 0;

	if (len == 1)
		return (len);
	else if (len == 0)
		return (-1);
	while (i < len)
	{
		if ((seen != 1) && (isalnum(buffer[i]) != 0))
			seen = 1;
		++i;
	}
	if (seen == 0)
		return (1);
	return (len);
}

/**
 * _add_bin_to_new_arg - A function to add "/bin/" path to arguements or not.
 * @args: modified arguments passed to the program.
 *
 * Return: char *.
 */
char *_add_bin_to_new_arg(char *const *args)
{
	char *new_arg = NULL;

	new_arg = malloc((sizeof(char) * 5) + strlen(args[0]));
	if (new_arg == NULL)
		return (NULL);
	strcat(new_arg, "/bin/");
	strcat(new_arg, args[0]);
	if ((access(new_arg, F_OK)) != 0)
	{
		free(new_arg);
		new_arg = malloc(sizeof(char) * strlen(args[0]));
		if (new_arg == NULL)
			return (NULL);
		strcat(new_arg, args[0]);
	}
	return (new_arg);
}
