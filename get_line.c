#include "main.h"

#define BUFF_SIZE 1024

/**
 * _getchar - works like getchar
 *
 * Return: always (EOF)
*/

int _getchar(void)
{
static int num;
static char buffer[BUFF_SIZE];
static char *buff_ptr = buffer;

/* read in the input */
if (num == 0)
{
/* get char from terminul */
num = read(0, buffer, sizeof(buffer));
buff_ptr = buffer;
}
/* */
if (--num >= 0)
{

return ((unsigned char) *buff_ptr++);
}

return (EOF);
}


/**
 * read_line - a function that reads input from terminal (works like 'getline')
 *
 * Return: the inputed string (buffer).
*/

char *get_line(void)
{
int i, c, buffSize = BUFF_SIZE;

/* allocating a buffer to store the input line */
char *buffer = malloc(sizeof(char) * buffSize);
if (!buffer)
{
perror("malloc");
exit(EXIT_FAILURE);
}
/* did loop will read the input char by char */
i = 0;
while (1)
{
c = _getchar();
if (c == EOF || c == '\n')
{
buffer[i] = '\0';
if (c == EOF && i == 0)
{
free(buffer);
return (NULL);
}
return (buffer);
}
else
{
buffer[i] = c;
}
i++;

if (i >= buffSize)
{
buffSize += BUFF_SIZE;
buffer = realloc(buffer, buffSize);
if (!buffer)
{
perror("malloc");
exit(EXIT_FAILURE);
}
}
}
return (buffer);
}
