#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>

int _putchar(char c);
void _puts(char *str);
int _strlen(char *str);
char *_strdup(char *src);
char *concat_all(char *str1, char *str2, char *str3);

char **splitstring(char *str, const char *delim);
void execute(char **argv);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);


extern char **environ;

/**
 * struct list_path - Linked list containing PATH directories
 * @dir: Directory in the PATH
 * @p: Pointer to the next node in the linked list
*/
typedef struct list_path
{
	char *dir;
	struct list_path *p;
} list_path;


char *_getenv(const char *name);
list_path *add_node_end(list_path **head, char *str);
list_path *linkpath(char *path);
char *_which(char *filename, list_path *head);

/**
 * struct mybuild - Pointer to function with corresponding buildin command
 * @name: The name of the built-in command
 * @func: A function pointer that executes the built-in command
*/
typedef struct mybuild
{
	char *name;
	void (*func)(char **);
} mybuild;

void(*checkbuild(char **arv))(char **arv);
int _atoi(char *s);
void exitt(char **arv);
void env(char **arv);
void _setenv(char **arv);
void _unsetenv(char **arv);

void freearv(char **arv);
void free_list(list_path *head);


#endif
