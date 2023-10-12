#ifndef shell_h
#define shell_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdbool.h>

/*str_function1*/
void _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
int _printn(int n);
int print_error(char *argv, unsigned int count, char *command, char *line);

/*str_function2*/
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int handle_cd(char **args);
int handle_echo(char **args);

/*exit*/
int handel_exit(char **args, char *line, int err, unsigned int cnt);
int if_num(char *s);
int _atoi(char *s);
void free_buffer(char **buffer);
void _env(char **env);

/*get_function*/
char *_getenv(const char *name);
char **_getargs(char *line);
char **_getdir(char *path);
char *path_checker(char **dir, char *args);
int if_exec(char *line);

/*simple_shell*/
int if_empty(char *line);
int _fork(char **args, char *line);
char *_readline(void);
int _exec(char **args, char *line, char *argv, unsigned int cnt);

/*getline*/
char *_getline();
char *_read_line();
int _read_line_loop(char *buffer, size_t *bufsize);
char *_initialize_buffer();
char *_realloc_buffer(char *buffer, size_t *bufsize);

/*chooseorder*/
void chooseorder(char **args, char **argv, int cnt);

/*_strtok*/
char *custom_strtok(char *str, const char *delim);
int custom_strchr(const char *str, char character);


#endif /* shell_h */
