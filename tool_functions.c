#include "main.h"
#include <stddef.h>

/* The tool functions: */

/**
 * _atoi - convert str to int
 * @str: pointer to string to convert
 *
 * Return: conv value
*/

int _atoi(const char *str)
{
int ans = 0, sign = 1;

if (*str == '-')
{

sign = -1;
++str;
}

else if (*str == '+')
{
++str;
}
/*loop*/
while (*str != '\0')
{
if (*str < '0' || *str > '9')
{
break;
}
ans = ans * 10 + (*str - '0');
++str;
}

return (ans * sign);
}


/**
 * _memcpy - copy n bytes from memory area src to dest
 *
 * @src: pointer to source memory area
 * @n: number of bytes to copy
 * @dest: pointer to destination memory area
 *
 * Return: pointer to destination memory area
*/

void *_memcpy(void *dest, const void *src, size_t n)
{
char *des_cp = (char *)dest;
size_t i;
const char *src_c = (const char *)src;
for (i = 0; i < n; i++)
{
des_cp[i] = src_c[i];
}
return (dest);
}

