#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 */
void _putchar(char c)
{
	write(STDERR_FILENO, &c, 1);
}
/**
 * _puts - prints a string, followed by a new line, to stdout
 * @str: The string to print
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		write(STDERR_FILENO, &str[i], 1);
}
/**
 * _strlen - returns the length of a string
 * @s: The string to get the length of it
 * Return: The length of the string
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}
/**
 * _printn - prints an integer
 * @num: The integer to print
 * Return: 0 on success, 1 on failure
 */
int _printn(int num)
{
	unsigned int n = num;
	char *num_str;
	int i, size = 0;

	if (num == 0)
	{
		_putchar('0');
		return (0);
	}

	while (n)
	{
		size++;
		n /= 10;
	}

	num_str = (char *)malloc(sizeof(char) * size);
	if (num_str == NULL)
	{
		return (1);
	}

	i = size - 1;
	while (num)
	{
		num_str[i] = '0' + (num % 10);
		num /= 10;
		i--;
	}

	i = 0;
	while (i < size)
	{
		_putchar(num_str[i]);
		i++;
	}
	free(num_str);
	return (0);
}

/**
 * print_error - prints error message
 * @argv: arguments
 * @count: count
 * @command: command
 * @alarm: alarm string to print
 * Return: void
 */
int print_error(char *argv, unsigned int count, char *command, char *alarm)
{
	_puts(argv);
	_puts(": ");
	if (_printn(count))
		return (-1);
	_puts(": ");
	_puts(command);
	_puts(": ");
	_puts(alarm);
	return (127);
}
