#include "shell.h"

/**
 * chooseorder - choose the order to execute
 * @args: arguments
 * @argv: argv
 * @cnt: counter
 * Return: void
 */
void chooseorder(char **args, char **argv, int cnt)
{
	int exstat = 0, err = 0;

	if (_strcmp(args[0], "cd") == 0)
	{
		if (handle_cd(args) == -1)
		{
			print_error(argv[0], cnt, args[0], "can't cd to ");
			_puts(args[1]);
			_putchar('\n');
			free_buffer(args);
			return;
		}
	}
	else if (_strcmp(args[0], "echo") == 0)
	{
		if (handle_echo(args) == -1)
		{
			_puts("echo: Error executing echo command\n");
			free_buffer(args);
			return;
		}
	}
	else if (_strcmp(args[0], "exit") == 0)
	{
		if (handel_exit(args, argv[0], err, cnt) == 2 && !isatty(0))
			exit(2);
	}
	else if (_strcmp(args[0], "env") == 0)
		_env();
	else
	{
		exstat = _exec(args, args[0], argv[0], cnt);
		err = errno;
		if (exstat == -1)
			free_buffer(args), exit(EXIT_FAILURE);
		else if (exstat == 127 && !isatty(0))
			free_buffer(args), exit(127);
	}
	free_buffer(args);
}
