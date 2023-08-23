#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define TOKEN_BUFSIZE 64

char *find_command_in_path(const char *command);
void handle_interactive(void);
void handle_non_interactive(void);
char *read_input(void);
int execute_builtin(char **args);
int execute_command_with_path(char **args);
void free_args(char **args);
void print_environment(void);
char **parse_input(char *input);

#endif

