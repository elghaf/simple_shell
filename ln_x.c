#include "shell.h"


/**
 * splitstring - splits a string and makes it an array of pointers to chras
 * @str: the string to cut
 * @delim: delem
 * Return: array of pointers to words
 */
char **splitstring(char *str, const char *delim)
{
	int count, word_count;
	char **result;
	char *bs;
	char *str_copy;

	str_copy = malloc(_strlen(str) + 1);
	if (str_copy == NULL)
	{
	perror(_getenv("_"));
	return (NULL);
	}
	count = 0;
	while (str[count])
	{
	str_copy[count] = str[count];
	count++;
	}
	str_copy[count] = '\0';

	bs = strtok(str_copy, delim);
	result = malloc((sizeof(char *) * 2));
	result[0] = _strdup(bs);

	count = 1;
	word_count = 3;
	while (bs)
	{
	bs = strtok(NULL, delim);
	result = _realloc(result, (sizeof(char *) * (word_count - 1)),
	(sizeof(char *) * word_count));
	result[count] = _strdup(bs);
	count++;
	word_count++;
	}
	free(str_copy);
	return (result);
}


/**
 * execute - a fucntion thta exe a cmx unix
 * @argv: array of arguments
 */

void execute(char **argv)
{

	int fdc, ps;

	if (!argv || !argv[0])
		return;
	fdc = fork();
	if (fdc == -1)
	{
		perror(_getenv("_"));
	}
	if (fdc == 0)
	{
		execve(argv[0], argv, environ);
			perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	wait(&ps);
}

/**
 * _realloc - Reallocate a block in memory
 * @ptr:ptr
 * @old_size: size of the ptr
 * @new_size: size for the pointer
 * Return: res Pointer
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *n_p;
	char *o;

	unsigned int i;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	n_p = malloc(new_size);
	o = ptr;
	if (n_p == NULL)
		return (NULL);

	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			n_p[i] = o[i];
		free(ptr);
		for (i = old_size; i < new_size; i++)
			n_p[i] = '\0';
	}
	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			n_p[i] = o[i];
		free(ptr);
	}
	return (n_p);
}

/**
 * freearv - frees the array of pointers arv in mem
 *@arv: an array of ptrs
 */

void freearv(char **arv)
{
	int cpt;

	for (cpt = 0; arv[cpt]; cpt++)
		free(arv[cpt]);
	free(arv);
}
