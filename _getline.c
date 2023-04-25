#include "main.h"

/**
 * line_reader - read the entered command line and
 *   convert it to a string.
 *
 * Return: the comand line as a string.
 */

char *_getline()
{
int bufsize = 1024;
int position = 0;
char *buffer = malloc(sizeof(char) * bufsize);
int c;

if (!buffer)
{
fprintf(stderr, "./hsh: allocation error\n");
exit(EXIT_FAILURE);
}

while (1)
{
/* Read a character */
c = getchar();

/* check if Ctrl-D in entered */
if (c == -1)
exit(EXIT_SUCCESS);

/* If we hit EOF or "\n", replace it */
/* with the null terminator and return. */
if (c == EOF || c == '\n') {
buffer[position] = '\0';
return buffer;
}

else
{
buffer[position] = c;
}
position++;

/* If we have exceeded the buffer, reallocate. */
if (position >= bufsize)
{
bufsize += bufsize;
buffer = realloc(buffer, bufsize);
if (!buffer)
{
fprintf(stderr, "./hsh: allocation error\n");
exit(EXIT_FAILURE);
}
}
}

return (buffer);
}
