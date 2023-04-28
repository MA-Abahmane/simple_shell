#include "main.h"

#define BUFF_SIZE 1024
#define SEPARATORS " \t\r\a\n"

/**
 * get_line_args - a function that seperates all arguments 
 *    in a string, then saves them in a 2D array
 * @line: given cmmand line
 *
 * Return: a 2D array containing the agruments (args)
 */

char **get_line_args(char *line)
{
int i, buffSize = BUFF_SIZE;

/* allocating space in memory for a 2D array  */
char **args = malloc(sizeof(char *) * buffSize), *arg;
if (!args)
{
write(STDERR_FILENO, "Allocation Error\n", _strlen("Allocation Error\n"));
exit(EXIT_FAILURE);
}

/* _strtok works like the original strtok */
arg = _strtok(line, SEPARATORS);
i = 0;
while (arg != NULL)
{
args[i] = arg;
++i;
/* if buffer limit exided, double the memory */
if (i >= buffSize)
{
buffSize += BUFF_SIZE;
args = realloc(args, sizeof(char *) * buffSize);
if (!args)
{
write(STDERR_FILENO, "Reallocation Error\n", _strlen("Reallocation Error\n"));
exit(EXIT_FAILURE);
}
}
/* point to the next arg */
arg = _strtok(NULL, SEPARATORS);
}
args[i] = NULL;
/* set the last argument to null and return */
return (args);
}
