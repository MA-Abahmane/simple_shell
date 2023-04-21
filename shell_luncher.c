#include "main.h"

/**
 * shell_luncher - a function that runs command on shell as child
 * and pauses the parant process until the child one is done.
 * @args: given command arguments.
 *
 * Return: process status (1 on success).
 */

int shell_luncher(char **args)
{

pid_t PID, PID_Wait;
int stat;

/* fork will help us run a new proccess */
PID = fork();
PID_Wait = 0;

/* run command line as child (execvp) */
if (PID == 0)
{
/* child process (Run command on shell) */
if (execvp(args[0], args) == -1)
{
perror("./shell");
}
exit(EXIT_FAILURE);
}

/* check if fork failed */
else if (PID < 0|| PID_Wait < 0)
{
perror("./shell");
}

else
{
do {
/* wait until the child process is done (our shell will wait) */
PID_Wait = waitpid(PID, &stat, WUNTRACED);
} while (!WIFEXITED(stat) && !WIFSIGNALED(stat));
}

return (1);
}
