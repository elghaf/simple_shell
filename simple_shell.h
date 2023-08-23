#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

void print_prompt(void);
char *read_input();
char **parse_input(char *line);
int execute(char **args);

#endif
