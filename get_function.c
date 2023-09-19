#include "shell.h"

/**
 * _getargs - splits a line into arguments
 * @line: line to split
 * Return: array of arguments
 */
char **_getargs(char *line)
{
	char **args = NULL, *token, *tmp, *tmp_token;
	int size = 0, i;

	tmp = _strdup(line);
	if (tmp == NULL)
		return (NULL);
	tmp_token = custom_strtok(tmp, " \t\n");
	while (tmp_token != NULL)
	{
		size++;
		tmp_token = custom_strtok(NULL, " \t\n");
	}
	free(tmp), size++;
	args = (char **)malloc(sizeof(char *) * size);
	if (args == NULL)
		return (NULL);
	for (i = 0; i < size - 1; i++)
	{
		token = custom_strtok((i ? NULL : line), " \t\n");
		args[i] = _strdup(token);
		if (args[i] == NULL)
		{
			for (i--; i >= 0; i--)
				free(args[i]);
			free(args);
			return (NULL);
		}
	}
	args[size - 1] = NULL;
	return (args);
}
/**
 * _getdir - gets the directory
 * @path: path to get
 * Return: the directory
 */
char **_getdir(char *path)
{
	char **dirs = NULL, *token, *tmp, *tmp_token;
	int size = 0, i;

	tmp = _strdup(path);
	if (tmp == NULL)
		exit(EXIT_FAILURE);
	tmp_token = custom_strtok(tmp, ":");
	while (tmp_token != NULL)
	{
		tmp_token = custom_strtok(NULL, ":");
		size++;
	}
	free(tmp), size++;
	dirs = (char **)malloc(sizeof(char *) * size);
	if (dirs == NULL)
		exit(EXIT_FAILURE);
	for (i = 0; i < size - 1; i++)
	{
		token = custom_strtok((i ? NULL : path), ":");
		dirs[i] = _strdup(token);
		if (dirs[i] == NULL)
		{
			for (i--; i >= 0; i--)
				free(dirs[i]);
			free(dirs);
			exit(EXIT_FAILURE);
		}
	}
	dirs[size - 1] = NULL;
	return (dirs);
}
/**
 *_getenv - gets the environment variable
 *@name: name of the variable
 *Return: the value of the variable
 */
char *_getenv(const char *name)
{
	char *value = NULL;
	int i = 0, j, k, test, size;

	while (__environ[i])
	{
		test = 1;
		for (j = 0; __environ[i][j] != '=' && name[j]; j++)
		{
			if (name[j] != __environ[i][j])
				test = 0;
		}
		if (test)
		{
			k = 0;
			for (size = j; __environ[i][size]; size++)
				;
			size -= j;
			j++;

			value = (char *)malloc(sizeof(char) * (size + 1));
			if (value == NULL)
				exit(EXIT_FAILURE);
			for (; __environ[i][j]; j++)
				value[k] = __environ[i][j], k++;
			value[k] = '\0';
			break;
		}
		i++;
	}
	return (value);
}
/**
 * path_checker - checks if the command is executable
 * @dirs: directories
 * @line: line to check
 * Return: the path if executable, NULL if not
 */
char *path_checker(char **dirs, char *line)
{
	struct stat st;
	int i = 0;
	char *test, *path;

	test = _strcat("/", line);
	if (test == NULL)
		exit(EXIT_FAILURE);
	for (i = 0; dirs[i]; i++)
	{
		path = _strcat(dirs[i], test);
		if (path == NULL)
		{
			free(test);
			exit(EXIT_FAILURE);
		}
		if (stat(path, &st) == 0 && st.st_mode && S_IXUSR)
		{
			free(test);
			return (path);
		}
		free(path);
	}
	free(test);
	return (NULL);
}
/**
 * if_exec - checks if the command is executable
 * @filename: name of the file
 * Return: 1 if executable, 0 if not executable and
 *        -1 if file does not exist
 */
int if_exec(char *filename)
{
	struct stat st;
	int i = 0, path = 0;

	while (filename[i])
	{
		if (filename[i] == '/')
		{
			path = 1;
			break;
		}
		i++;
	}
	if (stat(filename, &st) == 0 && path && st.st_mode && S_IXUSR)
		return (1);
	else if (stat(filename, &st) == 0 && path)
		return (0);
	return (-1);
}
