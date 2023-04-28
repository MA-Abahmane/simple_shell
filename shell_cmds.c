#include "main.h"

/**
 * cd_cmd - the Unix cd command
 * @args: given arguments
 *
 * Return: None
*/

void cd_cmd(char **args)
{
char *path;
char *pwd;

if (args[1] == NULL)
path = getenv("HOME");
else if (_strcmp(args[1], "-") == 0)
{
path = getenv("OLDPWD");
if (path == NULL)
{
perror("cd");
return;
}
}
else
path = args[1];
if (chdir(path) != 0)
{
perror("cd");
return;
}
else
{
pwd = getcwd(NULL, 0);
if (pwd == NULL)
{
perror("getcwd");
return;
}
else
{
setenv("OLDPWD", getenv("PWD"), 1);
setenv("PWD", pwd, 1);
free(pwd);
}
}
}


/**
 * setenv_cmd - Unix setenv command
 * @args: given args
 *
 * Return: NONE
*/

void setenv_cmd(char **args)
{
/* if 2 arguments are passed */
if (args[1] == NULL || args[2] == NULL)
{

perror("setenv");
return;
}
/* running setend commands */
if (setenv(args[1], args[2], 1) == -1)
{

perror("setenv");
return;
}

}

/**
 * unsetenv_cmd - the unix unsetenv command
 * @args: given arguments
 *
 * Return: NONE
*/

void unsetenv_cmd(char **args)
{
/* if no arguments are passed */
if (args[1] == NULL)
{

perror("unsetenv");
return;
}
/* running unsetend commands */
if (unsetenv(args[1]) == -1)
{

perror("unsetenv");
return;
}

}


/**
 * env_cmd - the Unix env command
 * @args: given args
 *
 * Return: NONE.
*/

void env_cmd(char **args)
{
char **envptr = environ;
/* error handling */
if (args == NULL)
return;
/* print the environment info */
while (*envptr != NULL)
{

write(STDOUT_FILENO, *envptr, _strlen(*envptr));
write(STDOUT_FILENO, "\n", 1);
envptr++;
}

}