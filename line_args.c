#include "main.h"
#define SEPARATORS " \t\r\n\a"

/**
 * line_args - a function that sets the separated arguments of a string
 *  into a 2D array.
 * @line: the string to process.
 *
 * Return: return the 2D array containing the sting lines
 *  arguments.
 */

char **line_args(char *line)
{
char *arg;
char **arg_arr;
int i, bufSize = 77;

/* allocating a 2D array to contain the cmd lines arguments */
arg_arr = malloc(sizeof(char *) * bufSize);
if (arg_arr == NULL)
{
fprintf(stderr, "./shell: allocation failed\n");
exit(EXIT_FAILURE);
}

/* strtok points to all the serarated arguments in the command
string (line) and returns a pointer to the first one (arg) */
i = 0;
arg = strtok(line, SEPARATORS);
while (arg != NULL)
{
arg_arr[i] = arg;
++i;

/* If buffer limit reached, double its size */
if (i >= bufSize)
{
bufSize += bufSize;
arg_arr = realloc(arg_arr, sizeof(char *) * bufSize);
if (arg_arr == NULL)
{
fprintf(stderr, "./shell: reallocation failed\n");
exit(EXIT_FAILURE);
}

}
/* point to the next arguments */
arg = strtok(NULL, SEPARATORS);
}

/* ending the 2D array with NULL and return */
arg_arr[i] = NULL;
return (arg_arr);
}
