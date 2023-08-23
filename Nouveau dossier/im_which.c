#include "main.h"
/**
 * im_which - gets the valid pathh of the entered command
 * @cmd: coammand string
 * @valid: integer pointer
 *
 * Return: the path string
 */
char *im_which(char *cmd, int *valid)
{
	char *pth, *pth_cpy, *the_tok, *file_path;
	size_t cmd_len, dir_len;
	struct stat buf;
	*valid = 0;
	if (stat(cmd, &buf) == 0)
	{
		*valid = 1;
		return (cmd);
	}
	pth = getenv("PATH");
	pth_cpy = strdup(pth);
	if (pth_cpy == NULL)
	{
		perror("Memory allocation error");
	}
	cmd_len = strlen(cmd);
	the_tok = strtok(pth_cpy, ":");
	while (the_tok != NULL)
	{
		dir_len = strlen(the_tok); /*the_tok aka path token*/
		file_path = malloc(cmd_len + dir_len + 2);
		strcpy(file_path, the_tok);
		strcat(file_path, "/");
		strcat(file_path, cmd);
		strcat(file_path, "\0");
		if (stat(file_path, &buf) == 0)
		{ /* stat return 0 if successfully executed and -1 otherwise;;*/
			free(pth_cpy);
			*valid = 1;
			return (file_path);
		}
		else
		{
			free(file_path);
			the_tok = strtok(NULL, ":");
		}
	}
	free(pth_cpy);
	return (cmd);
}
