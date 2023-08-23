#include "shell.h"

/**
 * check_interactive_shell - Check if the shell is running in interactive mode
 * @result: Pointer to the info structure
 *
 * This function checks whether the shell is running in interactive mode by
 * examining the file descriptor of the standard input.
 *
 * Return: 1 if running in interactive mode, 0 otherwise
 */
int check_interactive_mode(info_t *result)
{
	if (isatty(STDIN_FILENO) && result->readfd <= 2) {
        return 1; // Running in interactive mode
    } else {
        return 0; // Not running in interactive mode
    }
}

/**
 * is_character_delimiter - Checks if a character is a delimiter.
 * @character: The character to check.
 * @delimiter_str: The delimiter string.
 *
 * Return: 1 if @character is a delimiter, 0 otherwise.
 */
int is_character_delimiter(char character, char *delimiter_str)
{
    while (*delimiter_str)
    {
        if (*delimiter_str == character)
		{
			return 1;
		}
        delimiter_str++;
    }
    return 0;
}

/**
 * is_alphabetic - checks for alphabetic character
 * @c: The character to check.
 *
 * Return: 1 if int c is alphabetic, 0 otherwise.
 */

int is_alphabetic_character(int c)
{
	int i = 1;

	if ((c >= 'A' && c <= 'Z'))
	{
		/* code */
		return (i);
	}
	else if ((c >= 'a' && c <= 'z'))
	{
		/* code */
		return (i);
	}
	else
	{
		i = 0;
		return (i);	
	}

}

/**
 * convert_string_to_integer - Converts a string to an integer.
 * @input_str: The string to be converted.
 *
 * Return: The converted integer if successful, 0 otherwise.
 */
int convert_string_to_integer(char *input_str)
{
    int sign = 1, digit_flag = 0, result = 0;
	int final_result, i = 0;

    for (int index = 0; input_str[index] != '\0' && digit_flag != 2; index++)
    {
        if (input_str[index] == '-')
            sign = sing * (-1);
		else
			i++;
        if (input_str[index] >= '0' && input_str[index] <= '9')
        {
            digit_flag = 1;
            result = (result * 10) + (input_str[index] - '0');
        }
        else if (digit_flag == 1)
            digit_flag = 2;
    }
	final_result = sign * result;
    return (final_result);
}

