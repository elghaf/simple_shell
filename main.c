#include "shell.h"

/**
 * main - a shell replica
 * @ac: number of args passed
 * @av: the args passed
 * Return: 0.
 */

int main(__attribute__((unused)) int ac, char **av)
{
	int cmd_cnt = 0;

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			write(STDOUT_FILENO, "($) ", sizeof("($) "));
			get_keywords(av, &cmd_cnt);
		}
	}
	else
	{
		get_keywords(av, &cmd_cnt);
	}
	return (0);
}

/**
 * get_keywords - gets the keywords from terminal using getline
 * @av: the args passed in CLI
 * @cnt: number of cmd typed
 *
 * Return: void
 */

void get_keywords(char **av, int *cnt)
{
	char *line = NULL, **argv = NULL, *trim_line;
	size_t n = 0;
	ssize_t glread = 0;
	int argc = 0;

	/* getline and check for error */
	glread = getline(&line, &n, stdin);
	if (glread == -1)
	{
		print_error(errno);
		return;
	}
	trim_line = strtok(line, "\n");
	if (trim_line == NULL || strcmp(trim_line, "") == 0)
	{
		free_ptr(line);
		return; /* Ignore empty or whitespace-only input */
	}
	/* tokenize the keywords */
	argv = tokenize_keywords(line, &argc);
	if (argv == NULL)
	{
		print_function_error();
		free_ptr(line);
		return;
	}
	*cnt += 1;
	/* call the function for child process */
	child_process_execute(av, cnt, argv);
	free_ptr(line);
}

/**
 * child_process_execute - to call a child process
 * @av: arguments passed
 * @cnt: no of commands typed
 * @argv: array of argumnt
 * Return: void
 */

void child_process_execute(char **av, int *cnt, char **argv)
{
	int argc = 0, status = 0;
	char *exec_path;
	pid_t child_process;

	child_process = fork();
	if (child_process == -1)
	{
		print_error(errno);
		return;
	}
	if (child_process == 0)
	{
		exec_path = find_path(argv[0]);
		if (exec_path != NULL)
		{
			execve(exec_path, argv, NULL);
			if (execve(exec_path, argv, NULL) == -1)
			{
				perror("execve");
				_exit(98);
			}
			print_exec_err(av, *cnt, argv[0]);
			free_ptr(exec_path);
			_exit(98);
		}
		else
		{
			print_exec_err(av, *cnt, argv[0]);
			free_ptr_db(argv, argc);
			_exit(127);
		}
	}
	else
		wait(&status);

	argv[argc] = NULL;
	free_ptr_db(argv, argc);
}

/**
 * tokenize_keywords - tokenize the keywords passed into the tty
 * @line: the text/keys to tokenize
 * @argc: number of tokens
 *
 * Return: arrays of pointers to tokens
 */

char **tokenize_keywords(char *line, int *argc)
{
	char **argv = NULL, *token = NULL, *delim = " \n", *line_cpy = NULL;
	int i;

	if (line == NULL)
		return (NULL);
	/* duplicate string and increment argc for memalloc */
	line_cpy = strdup(line);
	if (line_cpy == NULL)
	{
		print_error(errno);
		return (NULL);
	}
	token = strtok(line_cpy, delim);
	while (token)
	{
		*argc += 1;
		token = strtok(NULL, delim);
	}
	free_ptr(line_cpy);
	argv = malloc(sizeof(char *) * (*argc));
	if (argv == NULL)
	{
		print_error(errno);
		return (NULL);
	}
	i = 0;
	token = strtok(line, delim);
	while (token)
	{
		argv[i] = strdup(token);
		if (argv[i++] == NULL)
		{
			free_ptr_db(argv, i);
			free_ptr(line);
			return (NULL);
		}
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	return (argv);
}

/**
 * find_path - takes command name as argument & search for full path
 * @command: the command name opassed as an arguement
 *
 * Return: full path if found, otherwise return NULL
 */

char *find_path(char *command)
{
	char *path_env, *path, *full_path;
	size_t full_path_len;
	bool path_type;

	path_type = (command[0] == '/');
	if (path_type && access(command, X_OK) == 0)
	{
		return (strdup(command)); /* Return a duplicated path */
	}
	path_env = getenv("PATH");
	if (path_env == NULL)
	{
		return (NULL);
	}
	path = strtok(path_env, ":");
	while (path != NULL)
	{
		full_path_len = strlen(path) + strlen(command) + 2;
		full_path = (char *)malloc(full_path_len);
		if (full_path == NULL)
		{
			return (NULL); /*Memory allocation error*/
		}
		if (path_type)
			strcpy(full_path, command);
		else
		{
			strcpy(full_path, path);
			strcat(full_path, "/");
			strcat(full_path, command);
		}
		if (access(full_path, X_OK) == 0)
		{
			return (full_path);
		}
		else
			free(full_path);
		path = strtok(NULL, ":");
	}
	return (NULL); /* Command not found*/
}
