#ifndef MAIN_H
#define MAIN_H

/* Library calls */
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>


/* the main functions */
void main_loop(void);
char *get_line(void);
char **get_line_args(char *line);
void command_executer(char **args, char *argv[]);


/* shell command functions*/
void cd_cmd(char **args);
void env_cmd(char **args);
void setenv_cmd(char **args);
void unsetenv_cmd(char **args);
void clear_cmd(char **args);
void exit_cmd(char **args);


/* tool functions */
int _strlen(char *str);
int _strcmp(const char *s1, const char *s2);
char *_strcat(char *dest, char *src);
char *_strtok(char *str, const char *delim);
char *_strchr(const char *str, int c);
char *_strcpy(char *dest, char *src);
void *_memcpy(void *dest, const void *src, size_t n);
int _atoi(const char *str);
int _isdigit(int c);
void errors(char *name);


/* External Variables */
extern int last_exit_status;
extern char **environ;


/**
 * struct user_comd - command matching func
 * @command: given cmd name
 * @command_fun: function to run the cmd
 *
*/

typedef struct user_comd
{
char *comd;
void (*command_func)(char **args);
} cmd_func_matcher;

#endif
