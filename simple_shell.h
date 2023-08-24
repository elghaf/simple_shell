#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

/*function to interact with the shell*/
void display_function(void);
char *read_user_input();
char **print_user_resutl(char *text_line);
int run_command(char **args);
void print_environment(void);

#endif
