#include "shell.h"

/**
 * handel_exit - handles the exit builtin
 * @args: arguments
 * @argv: argv[0]
 * @err: error number
 * @cnt: count of commands
 * Return: err value on success, 2 on error
 */
int handel_exit(char **args, char *argv, int err, unsigned int cnt)
{
	if (args[1])
	{
		if (if_num(args[1]))
		{
			err = errno = 2;
			print_error(argv, cnt, args[0], "Illegal number: ");
			_puts(args[1]);
			_putchar('\n');
			return (2);
		}
		err = _atoi(args[1]);
	}
	free_buffer(args);
	exit(err);
}
/**
 * if_num - checks if a string is a number
 * @s: string to check
 * Return: 1 if number, 0 if not
 */
int if_num(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (1);
	}
	return (0);
}
/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 * Return: integer
 */
int _atoi(char *s)
{
	int n = 0, i = 0, zero = 1;

	while (s[i])
	{
		if (s[i] != '0')
		{
			zero = 0;
			break;
		}
	}
	if (zero)
		return (0);
	for (i = 0; s[i]; i++)
	{
		n += (s[i] - '0');
		if (n != 0)
			n *= 10;
	}
	n /= 10;
	return (n);
}
/**
 * free_buffer - frees the buffer
 * @buffer: buffer to free
 * Return: void
 */
void free_buffer(char **buffer)
{
	int i;

	for (i = 0; buffer[i]; i++)
		free(buffer[i]);
	free(buffer);
}
/**
 * _env - prints the environment
 * Return: void
 */
void _env(void)
{
	unsigned int i = 0;

	while (__environ[i] != NULL)
	{
		_puts(__environ[i]);
		_puts("\n");
		i++;
	}
}
