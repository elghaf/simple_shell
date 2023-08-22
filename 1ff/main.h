#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <stdio.h>
#include <sys/wait.h>


// functions that need to start shell
void display_prompt(void);
char *get_input_line(void);

#endif