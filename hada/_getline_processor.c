#include "main.h"

/**
 * _getline_processor - A function used to process a line read from the stdin.
 * @args: modified arguements passed to the program.
 * @len: the total length of @args.
 * @buffer: unmodified arguements passed to the program.
 * @arr_size: size of array to be allocated.
 *
 * Return: char **.
 */
char **_getline_processor(char *const **args, ssize_t len, char *buffer,
	int arr_size)
{
	ssize_t i = 0;
	int x = 0, y = 0, z = 0;
	int arr_count = 0, *_arr_count = &arr_count;
	char **argv;

	argv = malloc(sizeof(char **) * arr_size);
	if (argv == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if ((buffer[i] == ' ') || ((i + 1) == len))
		{
			y = 0;
			z = x;
			while (x < i)
			{
				++y;
				++x;
				argv = _getline_alloc(argv, buffer, &_arr_count, x, i, arr_size, y, z);
				if (argv == NULL)
					return (NULL);
			}
			++x;
		}
		++i;
	}
	*args = &(*argv);
	return (argv);
}
