#ifndef MAIN_H
#define MAIN_H

/* Librarys */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Function prototypes */
int _putchar(char c);
void main_loop();
char *line_reader();
char **line_args(char *line);
int line_executer(char **args);
int shell_luncher(char **args);

#endif
