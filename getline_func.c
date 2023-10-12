#include "shell.h"

/**
 * _realloc_buffer - Reallocates memory for the input buffer.
 *
 * @buffer: Pointer to the buffer to be reallocated.
 * @bufsize: Pointer to the size of the buffer.
 *
 * Return: A pointer to the reallocated buffer or NULL on error.
 */
char *_realloc_buffer(char *buffer, size_t *bufsize)
{
	char *new_buffer = realloc(buffer, *bufsize);
	*bufsize += 64;

	if (!new_buffer)
	{
		perror("realloc");
		free(buffer);
	}

	return (new_buffer);
}

/**
 * _initialize_buffer - Initializes the input buffer.
 *
 * Return: A newly allocated buffer or NULL on error.
 */
char *_initialize_buffer()
{
	size_t bufsize = 10240;
	char *buffer = (char *)malloc(bufsize);

	if (!buffer)
	{
		perror("malloc");
		return (NULL);
	}

	return (buffer);
}

/**
 * _read_line_loop - Read characters and build the input line.
 *
 * @buffer: Pointer to the input buffer.
 * @bufsize: Pointer to the size of the buffer.
 *
 * Return: 1 on success, 0 on end of input, or -1 on error.
 */
int _read_line_loop(char *buffer, size_t *bufsize)
{
	size_t i = 0;

	while (1)
	{
		int bytes_read = read(STDIN_FILENO, &buffer[i], 1);

		if (bytes_read == 1)
		{
			if (buffer[i] == '\n')
			{
				buffer[i] = '\0';
				return (1);
			}
			i++;
		}
		else if (bytes_read == 0)
		{
			if (i == 0)
			{
				free(buffer);
				return (0);
			}
			buffer[i] = '\0';
			return (1);
		}
		else
		{
			perror("read");
			free(buffer);
			return (-1);
		}
		if (i >= *bufsize - 1)
		{
			buffer = _realloc_buffer(buffer, bufsize);
			if (!buffer)
			{
				return (-1);
			}
		}
	}
}

/**
 * _read_line - Read a line of text from standard input.
 *
 * Return: A pointer to the input string if successful, otherwise NULL.
 */
char *_read_line()
{
	char *buffer = _initialize_buffer();
	size_t bufsize = 10240;
	int result = _read_line_loop(buffer, &bufsize);

	if (!buffer)
	{
		return (NULL);
	}

	if (result == -1)
	{
		return (NULL);
	}

	if (result == 0)
	{
		return (NULL);
	}

	return (buffer);
}
/**
 *_getline - Reads a line of text from standard input and allocates memory.
 *
 *Return: A pointer to the input string if successful, otherwise NULL.
 */
char *_getline()
{
	return (_read_line());
}
