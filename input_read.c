#include <simple_shell.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * obtainUserInput - Obtain input from the user
 *
 * Return: The input line provided by the user
 */
char *obtainUserInput()
{
    char *inputLine = NULL;
    size_t bufferSize = 0;
    //get line
    getline(&inputLine, &bufferSize, stdin);
    return (inputLine);
}
