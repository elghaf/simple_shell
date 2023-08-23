#define MAX_READ 1024
#include "shell.h"

/**
 * _getline - Reads a line from a file stream
 * @lineptr: Pointer to a buffer to store the read line
 * @n: Pointer to the size of the buffer
 * @stream: The file stream to read from
 *
 * Return: The number of characters read, or -1 on error.
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static char buffer[MAX_READ];
	static size_t pos;
	static ssize_t read_count;

	if (*lineptr == NULL || *n == 0)
	{
		*n = MAX_READ;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}

	if (should_refill_buffer(pos, read_count))
	{
		if (refill_buffer(buffer, stream, &read_count, &pos, *n) == -1)
			return (-1);
	}

	return (extract_line(buffer, lineptr, &pos, read_count, n));
}

/**
 * should_refill_buffer - Checks if the buffer needs to be refilled
 * @pos: Current position in the buffer
 * @read_count: Number of characters read into the buffer
 *
 * Return: 1 if the buffer needs to be refilled, 0 otherwise.
 */

int should_refill_buffer(size_t pos, ssize_t read_count)
{
	return ((ssize_t)pos >= read_count);
}

/**
 * refill_buffer - Refills the buffer with data from a file stream
 * @buffer: Buffer to fill with data
 * @stream: The file stream to read from
 * @read_count: Pointer to the number of characters read
 * @pos: Pointer to the current position in the buffer
 * @n: Size of the buffer
 *
 * Return: 0 on success, -1 on error or end of file.
 */

int refill_buffer(char *buffer, FILE *stream, ssize_t *read_count,
		size_t *pos, size_t n)
{
	*read_count = read(fileno(stream), buffer, MAX_READ);
	if (*read_count == -1)
		return (-1);
	else if (*read_count == 0)
	{
		return ((*pos == 0) ? 0 : -1);
	}
	*pos = 0;
	return (0);
}

/**
 * extract_line - Extracts a line from the buffer
 * @buffer: Buffer containing the data
 * @lineptr: Pointer to a buffer to store the extracted line
 * @pos: Pointer to the current position in the buffer
 * @read_count: Number of characters read into the buffer
 * @n: Pointer to the size of the buffer
 *
 * Return: The number of characters extracted, or -1 on error.
 */

ssize_t extract_line(char *buffer, char **lineptr, size_t *pos,
		ssize_t read_count, size_t *n)
{
	size_t i = 0;

	while (i < (size_t)read_count)
	{
		if (buffer[*pos] == '\n')
		{
			(*pos)++;
			(*lineptr)[*pos] = '\0';
			return ((ssize_t)*pos);
		}
		if (*pos >= *n)
		{
			*n = *pos + 1;
			*lineptr = realloc(*lineptr, *n);
			if (*lineptr == NULL)
				return (-1);
		}
		(*lineptr)[*pos] = buffer[*pos];
		i++;
		(*pos)++;
	}
	(*lineptr)[*pos] = '\0';
	return ((ssize_t)*pos);
}
