#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

/* Define constants */
#define TOKEN_BUFSIZE 64
#define TOKEN_DELIMITERS " \t\r\n\a"

/* Function declarations */
char *obtainUserInput();
char **tokenizeUserInput(char *userInput);
int runCommand(char **arguments);
void display_prompt(void);

#endif
