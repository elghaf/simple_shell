#ifndef SHELL_H
#define SHELL_H

#define _POSIX_C_SOURCE 200809L
#define MAX_TOKENS 100
#define BUFFER_t 1024

extern char **environ;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

unsigned int equal(char cut, const char *string);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_strtok(char *str, const char *delim);
void path(void);
char *getcmd(void);
char *getpath(char *cmd);
char **get_token(char *cmd, char *delim);
void free_args(char **args);
void __exit(char **args);
char *_getenv(const char *name);
int _env(char *args);
int _cd(char *path);
int executor(const char *path, char **args);
int execute_builtin_commands(char **args);
int execute_external_command(char *path, char *cmd, char **args);
void shell_loop(void);
int _setenv(char **args);
int _unsetenv(char **args);

#endif /*SHEEL_H*/


