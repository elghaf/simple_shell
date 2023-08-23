#ifndef SHELL_H
#define SHELL_H

/* Define constants */
#define TOKEN_BUFSIZE 64
#define TOKEN_DELIMITERS " \t\r\n\a"


char *obtainUserInput();
char **tokenizeUserInput(char *userInput);
int runCommand(char **arguments)
void display_prompt(void);

#endif
