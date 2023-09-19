#include "shell.h"

/**
 * custom_strchr - custom strchr function
 * @str: string to check
 * @character: character to check for
 * Return: 1 if found, 0 if not
 */

int custom_strchr(const char *str, char character)
{
	unsigned int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == character)
			return (1);
		i++;
	}
	return (0);
}
/**
 * custom_strtok - custom strtok function
 * @str: string to tokenize
 * @delim: delimiter to tokenize by
 * Return: tokenized string
 */
char *custom_strtok(char *str, const char *delim)
{
	static char *save, *token;
	int i;

	if (str != NULL)
		save = str;
	token = save;
	if (token == NULL)
		return (NULL);
	for (i = 0; token[i] != '\0'; i++)
	{
		if (custom_strchr(delim, token[i]) == 0)
			break;
	}
	if (save[i] == '\0' || save[i] == '#')
	{
		save = NULL;
		return (NULL);
	}
	token = save + i;
	save = token;
	for (i = 0; save[i] != '\0'; i++)
	{
		if (custom_strchr(delim, save[i]) == 1)
			break;
	}
	if (save[i] == '\0')
		save = NULL;
	else
	{
		save[i] = '\0';
		save = save + i + 1;
		if (*save == '\0')
			save = NULL;
	}
	return (token);
}
