#include "main.h"


/**
 * cd - a function that opens directorys.
 * @args: arguments
 * Return: 1.
 */
/* The cd command  */
int cd(char **args)
{
/* if "cd" is ran alone */
if (args[1] == NULL)
{
char *home_dir = getenv("HOME");
if (home_dir == NULL)
{
return (1);
}

if (chdir(home_dir) != 0)
{
perror("./hsh");
}
return (1);
}

else
{
if (chdir(args[1]) != 0)
{
perror("./hsh");
}
}
return (1);
}


/**
 * Exit - a function that exits the main_loop.
 *
 * Return: Always 0.
 */
/* The exit command */
int Exit(void) { return (0); }


/**
 * cmds - a list of file names to run comands.
 *
 */

char *comds[] = {
"cd",
"exit",
NULL
};


/**
 * cmd_functions - a list that contains pointers to
 *   to the command functions.
 * @cmd_functions: somet.
 */

int (*cmd_functions[]) (char **) = {
&cd,
&Exit
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
while (comds[i] != NULL)
{

if (strcmp(args[0], comds[i]) == 0)
return ((*cmd_functions[i]) (args));

++i;
}

/* if not, run the command on an actual shell! */
return (shell_luncher(args));
}

