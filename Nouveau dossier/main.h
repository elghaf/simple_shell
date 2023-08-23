#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>

int checkargs(int arg, char **ac);
int brkdown_args(char *buffer);
int execute_file(char **buffer, int buff_size);
char *handle_comment(char *str_input);
int exit_com(char **buffer, int buff_size);
int isdelimiter(char c, char *delimiter);
char *_strtok(char *str, char *delimiter);
void free_buff(char **buffer, int buff_size);
void environ(void);
void handle_coms(char **buffer, char *str);
int _setenv(char *name, char *value);
int unset(char *name);
int _cd(char *path);
char *_getenv(char *name);
void print_builtin_error(char *msg, char *arg);
void cd_home(char **buffer);
char *get_first_av(void);
void custom_error(char *msg);
void task(char *name, char *value, int num);

#endif /*MAIN_H*/
