#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;

void print_prompt(char *prompt);
char **tokenizeLine(char *str, const char *delim);
void execute_command(char **av);
char *get_path(char *command);
int exit_command(char *command);
void print_env(void);

#endif

