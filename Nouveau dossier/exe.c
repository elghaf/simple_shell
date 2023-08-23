#include "main.h"
/**
 * exe - executes the command
 * @argv: array of arguments
 * @env: array of environment variables
 */
void exe(char **argv, char **env)
{
	char *cmd = NULL;
	char *the_real_cmd = NULL;
	int is_valid, c_status;
	pid_t c_pid;

	if (argv)
	{
		cmd = argv[0];
		the_real_cmd = im_which(cmd, &is_valid);
		if (is_valid == 1)
		{
			c_pid = fork();
			if (c_pid == -1)
			{
				perror("$Error");
			}
			if (c_pid == 0)
			{
				printf("trying to execute");
				if (execve(the_real_cmd, argv, env) == -1)
				{
					perror("$Error");
				}
			}
			else
			{
				wait(&c_status);
			}
		}
		else
		{
			if (execve(the_real_cmd, argv, env) == -1)
			{
				perror("$Error");
			}
		}
	}
}

