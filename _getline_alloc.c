#include "main.h"

/**
 * _getline_alloc - A function used to allocate memory to store
 * the modified arguements passed to the program.
 * @argv: modified arguements passed to the program.
 * @buffer: unmodified arguements passed to the program.
 * @arr_count: number of array of pointers to be created.
 * @x: used to monitor an index at @argv.
 * @i: used to monitor an index at @argv.
 * @arr_size: size of array to be allocated.
 * @y: used to monitor an index at @argv.
 * @z: used to monitor an index at @argv.
 *
 * Return: char **.
 */
char **_getline_alloc(char **argv, char *buffer, int **arr_count, int x,
	int i, int arr_size, int y, int z)
{
	int a;

	if (x == i)
	{
		if (**arr_count <= arr_size)
		{
			if (**arr_count < arr_size)
			{
				argv[**arr_count] = malloc(sizeof(char) * y);
				if (argv[**arr_count] == NULL)
					return (NULL);
				a = 0;
				while (z < i)
				{
					argv[**arr_count][a] = buffer[z];
					++a;
					++z;
				}
				argv[**arr_count][a] = '\0';
				**arr_count = **arr_count + 1;
			}
			if (**arr_count == arr_size)
			{
				argv[**arr_count] = malloc(sizeof(char *) * 1);
				if (argv[**arr_count] == NULL)
					return (NULL);
				argv[**arr_count] = NULL;
			}
		}
	}
	return (argv);
}
