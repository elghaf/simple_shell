#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * main - Entry to shell command
 * @ac: command arg count
 * @arv: command arg array
 * 
 * Return: 0 if success -1 otherwise null
 * 
 */


int main(int argc, char **argv) {
    const char *prompt = "$ ";
    char *input_line = NULL;
    char **command_tokens;
    size_t line_length = 0;
    ssize_t num_chars;
    const char *delimiter = " \n";

    (void)argc, (void)argv;

    while (1) {
        display_prompt(prompt);
        num_chars = getline(&input_line, &line_length, stdin);
        if (num_chars == -1) {
            free(input_line);
            return -1;
        }
        input_line[num_chars - 1] = '\0';
        command_tokens = tokenize_input_line(input_line, delimiter);
        if (command_tokens == NULL || *command_tokens == NULL || **command_tokens == '\0') {
            free(input_line);
            continue;
        }
        if (is_exit_command(command_tokens[0])) {
            break;
        }

        if (compare_strings(command_tokens[0], "env") == 0) {
            print_environment();
        } else {
            execute_user_command(command_tokens);
        }
    }

    free(input_line);
    return 0;
}
