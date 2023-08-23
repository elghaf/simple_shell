#include "simple_shell.h"
/**
 * parse_input - Fuctn splits str into arr of tokens
 * @input: Input str to be parsed
 *
 * Fuctn tokenizes input str based on a set of delimiters
 *
 * Return: An arr of pointrs to the tokens parsed from the input str
 *
 */
char **parse_input(char *input) {
    const char *delimiters = " \t\r\n\a";
    char *token;
    int bufsize = TOKEN_BUFSIZE;
    int position = 0;

    char **tokens = malloc(TOKEN_BUFSIZE * sizeof(char *));
    if (tokens == NULL) {
        perror("allocation error");
        exit(EXIT_FAILURE);
    }

    token = strtok(input, delimiters);

    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufsize) {
            bufsize += TOKEN_BUFSIZE;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (tokens == NULL) {
                perror("allocation error");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, delimiters);
    }
    tokens[position] = NULL;
    return tokens;
}

