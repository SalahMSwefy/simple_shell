#include "shell.h"

/**
 * handle_cd - change the current working directory
 * @args: arguments passed to cd
 * Return: 0 on success, -1 on failure
 */
int handle_cd(char **args)
{
	if (args[1] == NULL)
	{
		if (chdir(getenv("HOME")) != 0)
		{
			return (-1);
		}
	}
	else if (strcmp(args[1], "-") == 0)
	{
		char *oldpwd = getenv("OLDPWD");

		if (oldpwd == NULL)
		{
			fputs("cd: OLDPWD not set\n", stderr);
			return (-1);
		}

		if (chdir(oldpwd) != 0)
		{
			return (-1);
		}

		puts(oldpwd);
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			return (-1);
		}
	}

	return (0);
}
