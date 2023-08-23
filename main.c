#include "main.h"
/**
 * main - Entry point of the program
 * @argc: number of arguments
 * @argv: array of arguments
 * @env: array of environment variables
 *
 * Return: 0 (Success), 1 on error
 */
int  main(int argc, char **argv, char **env)
{
	char *buf_ad, *prompt = "chill_shell$ ", *out;
	size_t x = 0;
	ssize_t num_in;
	int exit = 0, status = 0;
	(void) argc;
	
	while (1)
	{
		printf("%s", prompt);
		num_in = getline(&buf_ad, &x, stdin);
		/*buf_ad = the_holy_getline();*/
		if (num_in == -1)
		{
			printf("Exiting.......\n");
			return (1);
		}
		argv = tokenize(buf_ad);
		status = builtin(argv, env, &exit);
		if (exit)
		{
			return (status);
		}
		exe(argv, env);
		/*out = the_holy_getline();
		printf("was entered: %s\n", out);*/
	}
	free(argv);
	free(buf_ad);
	free(out);
	return (0);
}
