#include "main.h"

/**
 * errors - a function that prints error message
 * @name: command name
 *
 * Return: NONE
*/

void errors(char *name)
{
/* get the name error */
perror(name);
}


