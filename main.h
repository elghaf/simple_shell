#ifndef MAIN_H
#define MAIN_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

char **tokenize(char *buf);
int builtin(char **argv, char **env, int *exit);
void exe(char **argv, char **env);
char *im_which(char *cmd, int *valid);
char* the_holy_getline();

#endif
