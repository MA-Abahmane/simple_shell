#include "main.h"


/**
 * _isdigit - check if a charracter is a digit
 * @c: given character
 *
 * Return: 0\1
*/

int _isdigit(int c)
{
/* */
return (c >= '0' && c <= '9');
}


/**
 * _strcpy - functions like strcpy: man strcpy
 * @src: the source
 * @dest: given destination
 *
 * Return: Destination.
*/
char *_strcpy(char *dest, char *src)
{

int i;

i = 0;
while (*(src + i) != '\0')
{

*(dest + i) = *(src + i);
i++;
}
*(dest + i) = *(src + i);

return (dest);
}


/**
 * _strcat - works like strcat
 * @src: the source
 * @dest: given destination
 *
 * Return: destination
 */

char *_strcat(char *dest, char *src)
{
int i, des_len = _strlen(dest);

i = 0;
while (*(src + i) != '\0')
{
*(dest + des_len) = *(src + i);

++i;
++des_len;
}
*(dest + des_len) = '\0';

return (dest);
}

/**
 * _strlen - works like strlen()
 * @str: given string
 *
 * Return: string lenght
*/

int _strlen(char *str)
{
int len;

len = 0;
while (*(str + len) != '\0')
{

++len;
}

return (len);
}
