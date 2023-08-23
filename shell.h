#ifndef SHELL_H
#define SHELL_H

/* Feature Test Macro Requirement for glibc getline() */
#define _GNU_SOURCE

/* Necessary header file */
#include <stdio.h> /* i/o functionality */
#include <errno.h> /* error type-check */
#include <unistd.h> /* unix standard */
#include <string.h> /* string manipulation header file */
#include <sys/types.h> /* definition of integer constants */
#include <sys/wait.h> /* to implement the wait() */
#include <stdlib.h> /* stadard library */
#include <stdbool.h> /* to use for boolean datatypes */

/* FUNCTION PROTOTYPES  */

/* keyword functions */
void get_keywords(char **, int *);
void child_process_execute(char **av, int *cnt, char **argv);
char **tokenize_keywords(char *, int *);
char *find_path(char *command);


/* error functions */
void print_error(int);
void print_function_error(void);
void print_exec_err(char **, int, char *);


/* Freeing functions */
void free_ptr(char *);
void free_ptr_db(char **, int);



#endif /* SHELL Header File */
