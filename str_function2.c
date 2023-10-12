#include "shell.h"

/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 0 if equal, -1 if less, 1 if greater
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;

	return (s1[i] - s2[i]);
}
/**
 * _strdup - duplicates a string
 * @str: string to copy
 * Return: pointer to new string
 */
char *_strdup(char *str)
{
	char *dup;
	int i, len = 0;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
		len++;
	dup = (char *)malloc((sizeof(char) * len) + 1);
	if (dup == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}
/**
 * _strcat - concatenates two strings
 * @dest: string 1
 * @src: string 2
 * Return: pointer to new string
 */
char *_strcat(char *dest, char *src)
{
	int i, j, k;
	char *str;

	for (i = 0; dest[i]; i++)
		;
	for (j = 0; src[j]; j++)
		;
	str = (char *)malloc(sizeof(char) * (i + j + 1));
	if (str == NULL)
		return (NULL);
	for (k = 0; k < i; k++)
		str[k] = dest[k];
	for (k = 0; k < j; k++)
		str[k + i] = src[k];
	str[i + j] = '\0';
	return (str);
}

/**
 * handle_echo - handle the echo command
 * @args: arguments passed to echo
 * Return: 0 on success, -1 on failure
 */
int handle_echo(char **args)
{
	int i = 1;
	bool needs_space = false;
	char *arg = args[i], *ch = arg, quote_char;

	while (args[i] != NULL)
	{
		if (needs_space)
			_putchar(' ');
		while (*ch)
		{
			if (*ch == '\\' && *(ch + 1) != '\0')
			{
				switch (*(ch + 1))
				{
				case 'n':
					_putchar('\n');
					ch += 2;
					continue;
				default:
					_putchar(*ch), ch++;
					continue;
				}
			}
			else if (*ch == '\'' || *ch == '"')
			{
				quote_char = *ch;
				ch++;
				while (*ch && *ch != quote_char)
					_putchar(*ch), ch++;
				if (*ch == quote_char)
					ch++;
			}
			else
				_putchar(*ch), ch++;
		}
		needs_space = true;
		i++;
	}
	_putchar('\n');
	return (0);
}
