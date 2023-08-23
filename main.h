#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

void display_prompt(const char *prompt);
//char **tokenize_input_line(char *input_line, const char *delimiter);
//int is_exit_command(const char *cmd);
//int compare_strings(const char *str1, const char *str2);
//void print_environment();
void execute_user_command(char **command_tokens);
char *get_full_path(char *command);

#endif /* MAIN_H header*/
