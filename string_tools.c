#include "main.h"


/**
 * _strtok - works like strtok.
 * @str: given string
 * @delim: given delims
 *
 * Return: Nothing.
*/

char *_strtok(char *str, const char *delim)
{
char *start, *end;
static char *p;

if (str)
{
p = str;
}

if (!p)
return (NULL);

while (*p && strchr(delim, *p))
{
p++;
}

if (!*p)
{
return (NULL);
}

start = p;
end = start + strcspn(p, delim);
/* */
p = (*end) ? end + 1 : NULL;

*end = '\0';
return (start);
}


/**
 * _strdup - works like strdup.
 * @str: given str
 *
 * Return: str.
*/

char *_strdup(char *str)
{
char *newStr;
int len = _strlen(str);

/* acclocation */
newStr = malloc(sizeof(char) * (len + 1));
if (newStr == NULL)
{
perror("malloc failed");
exit(EXIT_FAILURE);
}

_strcpy(newStr, str);
return (newStr);
}


/**
 * _strcmp - works like strcmp
 * @s1: given string
 * @s2: given string
 *
 * Return: always (s1 - s2)
*/

int _strcmp(const char *s1, const char *s2)
{


while (*s1 != '\0' && *s2 != '\0')
{

if (*s1 != *s2)
{
return (*s1 - *s2);
}
s1++;
++s2;
}

return (*s1 - *s2);
}


/**
 * _strchr - works like strchr
 * @str:  given string
 * @c: given integer
 *
 * Return: NULL on fail
*/

char *_strchr(const char *str, int c)
{

while (*str != (char)c && *str != '\0')
{

++str;
}

return ((*str == (char)c) ? (char *)str : NULL);
}