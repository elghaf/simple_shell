#include "main.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * print_environ - prints shell environment
 *
 * Return: void
 */
void display_prompt(char *prompt)
{
	char prompt[] = "ayoub $> ";

    printf("%s", prompt);

}
