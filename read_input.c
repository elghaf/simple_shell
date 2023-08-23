#include "simple_shell.h"
#define BUFFER_SIZE 1024
/**
 * read_input - This fuctn reads input frm standrd input and return a line
 *
 * It reads input frm the standrd input char by char
 * Return: Dynamically allocated str containing the input line,
 * or Null
 */

char *read_input(void)
{
static char buffer[BUFFER_SIZE];
static size_t buffer_position;
static ssize_t buffer_size;
char *line = NULL;
size_t line_length = 0;

if ((size_t)buffer_position >= (size_t)buffer_size)
{
buffer_size = read(STDIN_FILENO, buffer, sizeof(buffer));
if (buffer_size <= 0)
{
return (NULL);
}
buffer_position = 0;
}
while ((size_t)buffer_position < (size_t)buffer_size)
{
char c = buffer[buffer_position++];
if (c == '\n')
{
line = malloc(line_length + 1);
if (line == NULL)
{
perror("allocation error");
exit(EXIT_FAILURE);
}
memcpy(line, buffer, line_length);
line[line_length] = '\0';
return (line);
}
else
{
line_length++;
}
}
return (NULL);
}

