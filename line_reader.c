#include "main.h"

/**
 * line_reader - read the entered command line and
 *   convert it to a string.
 *
 * Return: the comand line as a string.
 */

char *line_reader()
{
int cmd_len;
char *cmd_str;
size_t bufSize;

/* getline() allocates memory for us and sets the given */
/* comand line in cmd_str as a string */
cmd_str = NULL;
bufSize = 0;

cmd_len = getline(&cmd_str, &bufSize, stdin);

/* check if EOF is true ("Ctrl-D") or "exit" is inputed */
if (cmd_len == -1 || strcmp(cmd_str, "exit\n") == 0)
{
exit(EXIT_SUCCESS);
}

return (cmd_str);
}
