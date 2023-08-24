#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

/* Define TOEKN BUFER SIZE */
#define TOKEN_BUFSIZE 64
#define TOKEN_DELIMITERS " \t\r\n\a"


/*function to interact with the shell*/
void display_function(void);
char *read_user_input();
char **print_user_resutl(char *text_line);
int run_command(char **arguments);

#endif
