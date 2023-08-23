#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void _shell(int, char **, char **, int);
void _env(char **);
char *_shell_command_checks(char *const *, ssize_t, char **, char **);
void _fork(char *, char *const *, char *, char **, int, char **, int **);
ssize_t _getline(char *const **, int **);
char **_getline_processor(char *const **, ssize_t, char *, int);
char **_getline_alloc(char **, char *, int **, int, int, int, int, int);
void _exit_(char *const *, char **, ssize_t size, char **);
ssize_t _getline_len_check(ssize_t, char *);
char *_add_bin_to_new_arg(char *const *args);
#endif
