#include "main.h"

/**
 * main - The main functions.
 * @argv: array of arguments
 * @argc: array length
 *
 * Return: Always 0
*/

int main(int argc, char *argv[])
{
char *prmpt = "#cisfun$ ";

char *line, **line_args;
int stat = 1;

(void)argc;

do {
/* Print the promp */
if (isatty(STDIN_FILENO))
{
write(STDIN_FILENO, prmpt, _strlen(prmpt));
}

/* get command line and check if its empty */
line = get_line();
if (line == NULL)
{

free(line);
break;
}

/* get command line arguments */
/* if line arguments array in not null, execute*/
line_args = get_line_args(line);
if (line_args[0] != NULL)
{

/* execute the command line arguments */
command_executer(line_args, argv);
free(line_args);
}
free(line);

} while (stat);
/* while stat is true; keep looping */
return (0);
}
