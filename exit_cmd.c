#include "main.h"


/**
 * exit_cmd - unix exit command
 * @args: given arguments to check
 *
 * Return: NONE
*/
int str_to_int(const char *s);
void exit_cmd(char **args)
{
int exit_stat;
char *Error_mes = "Invalid exit status: ";

exit_stat = 0;
if (args[1])
{
exit_stat = str_to_int(args[1]);
/* Error printer */
if (exit_stat < 0)
{
write(STDERR_FILENO, Error_mes, _strlen(Error_mes));
write(STDERR_FILENO, args[1], _strlen(args[1]));
write(1, "\n", 1);
return;
}
}
/* run exit */
_exit(exit_stat);
}

/**
 * str_to_int - it converets a string to an integer
 * @s: given string
 *
 * Return: 0/-1
*/

int str_to_int(const char *s)
{
int n, signe = 1;
long int ans = 0;

/* singe check */
if (*s == '-')
{
signe = -1;
++s;
}
else if (*s == '+')
{
s++;
}
/* convertion loop */
while (*s != '\0')
{
if (*s < '0' || *s > '9')
{
return (-1);
}
n = (*s - '0');
ans = (ans * 10 + n);
/* */
if ((signe == -1 && -ans < INT_MIN) || (signe == 1 && ans > INT_MAX))
{
return (-1);
}
++s;
}
return (signe * ans);
}