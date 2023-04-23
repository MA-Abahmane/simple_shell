#include "main.h"

/**
 * cd - a function that opens directorys.
 *
 * Return: 1.
 */
/* The cd command  */
int cd(char **args)
{
if (args[1] == NULL)
{
fprintf(stderr, ".\\shell: expected argument after cd\n");
}
else
{
if (chdir(args[1]) != 0)
{
perror("Error");
}
}
return (1);
}

/**
 * echo - a function that thus alot of stuff.
 * @args: given command arguments.
 *
 * Return: nothing.
 */
/* The exit command */

int echo(char **args)
{
int i = 1;

if (args[1] != NULL)
{
while (args[i + 1]  != NULL)
{
printf("%s ", args[i]);
++i;
}
printf("%s\n", args[i]);
}

else
fprintf(stderr, ".\\shell: expected argument after echo\n");

return (1);
}


/**
 * cmds - a list of file names to run comands.
 *
 */
/* commands list */

char *cmds[] ={
"cd", "echo", NULL
};

/**
 * cmd_functions - a list that contains pointers to
 *   to the command functions.
 */
/* command functions list */
int (*cmd_functions[])(char **) ={
&cd,
&echo
};


/*******[[[ The Command Executer ]]]*******/

/**
 * line_executer - a function that executes the commands the
 *    user entered (This is where the magic Happens).
 * @args: given command arguments.
 *
 * Return: process status.
 */

int line_executer(char **args)
{
int i;

if (args[0] == NULL)
return (1);

/* check if the command function are present, then call them.. */
i = 0;
while (cmds[i] != NULL)
{

if (strcmp(args[0], cmds[i]) == 0)
return ((*cmd_functions[i]) (args));

++i;
}

/* if not, run the command on an actual shell! */
return (shell_luncher(args));
}

