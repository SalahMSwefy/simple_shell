#include "shell.h"

/**
 * if_empty - checks if the line is empty
 * @line: line to check
 * Return: 1 if empty, 0 if not
 */
int if_empty(char *line)
{
	int i;

	if (line[0] == '\0' || _strcmp(line, "\n") == 0)
		return (1);

	for (i = 0; line[i]; i++)
	{
		if (line[i] != ' ' && line[i] != '\n' && line[i] != '\t')
			return (0);
	}
	return (1);
}
/**
 * _fork - forks the process
 *@args: arguments
 *@line: line to free
 * Return: 0 on success, -1 on failure
 */
int _fork(char **args, char *line)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		return (-1);
	}
	else if (child_pid == 0)
	{
		if (execve(line, args, __environ) == -1)
			perror(args[0]);
	}
	else if (child_pid > 0)
	{
		wait(&status);
		if (WIFEXITED(status))
			errno = (WEXITSTATUS(status));
	}
	return (0);
}
/**
 * _readline - reads a line from stdin
 * Return: The line from stdin
 */
char *_readline(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	line = _getline(&line, &bufsize, stdin);
	if (!line)
	{
		return (NULL);
	}

	return (line);
}
/**
 * _exec - executes the command
 * @args: arguments
 * @line: line to free
 * @argv: argv
 * @cnt: counter
 * Return: 0 on success, -1 on failure
 */
int _exec(char **args, char *line, char *argv, unsigned int cnt)
{
	char *path = _getenv("PATH"), *checkedpath = NULL, **dirs = NULL;
	int exec_checker = if_exec(line), err = 0, path_test = 0;

	if (exec_checker == 1)
	{
		if (_fork(args, line) == -1)
			return (-1);
	}
	else if (path != NULL && path_test == 0)
	{
		dirs = _getdir(path);
		checkedpath = path_checker(dirs, line);
		if (checkedpath != NULL)
		{
			path_test = 1;
			if (_fork(args, checkedpath) == -1)
				return (-1);
		}
	}
	if (path_test == 0)
	{
		if (exec_checker == 0)
			err = print_error(argv, cnt, args[0], "Permission denied\n");
		else if (exec_checker == -1)
			err = print_error(argv, cnt, args[0], "not found\n");
	}
	if (path)
		free(path);
	if (checkedpath)
		free(checkedpath);
	if (dirs)
		free_buffer(dirs);
	return (err);
}
/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Arguments
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	char *line = NULL, **args = NULL;
	unsigned int cnt = 0;

	(void)argc;
	while (++cnt)
	{
		if (isatty(0))
			_puts(":> ");
		line = _readline();
		if (line == NULL)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		if (if_empty(line))
		{
			free(line);
			continue;
		}
		args = _getargs(line);
		free(line);
		if (args == NULL)
			exit(EXIT_FAILURE);
		chooseorder(args, argv, cnt);
	}
	return (0);
}
