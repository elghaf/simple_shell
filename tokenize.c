#include <simple_shell.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * tokenizeUserInput - Tokenize user input into an array of tokens
 * @userInput: The input line to be tokenized
 *
 * Return: An array of tokens
 */
char **tokenizeUserInput(char *userInput)
{
    int tokenBufferSize = TOKEN_BUFSIZE;
    int tokenPosition = 0;
    char **tokenArray = (char **)malloc(tokenBufferSize * sizeof(char *));
    char *token;

    if (!tokenArray)
    {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(userInput, TOKEN_DELIMITERS);
    while (token != NULL)
    {
        tokenArray[tokenPosition] = token;
        tokenPosition++;

        if (tokenPosition >= tokenBufferSize)
        {
            tokenBufferSize += TOKEN_BUFSIZE;
            tokenArray = (char **)realloc(tokenArray, tokenBufferSize * sizeof(char *));
            if (!tokenArray)
            {
                fprintf(stderr, "Memory allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, TOKEN_DELIMITERS);
    }
    tokenArray[tokenPosition] = NULL;
    return tokenArray;
}
