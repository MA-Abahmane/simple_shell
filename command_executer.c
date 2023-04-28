#include "main.h"

#define BUFF_SIZE 1024


/* This list is used to match the command unput to its func */
static cmd_func_matcher input_cmds[6] = {
{"cd", cd_cmd},
{"env", env_cmd},
{"setenv", setenv_cmd},
{"unsetenv", unsetenv_cmd},
{"exit", exit_cmd},
};

/**
 * find_cmd - get the inputed commands
 * @cmd_name: given command name
 *
 * Return: the commands on success, or NULL
*/

cmd_func_matcher *find_cmd(char *cmd_name)
{
int i;
int num_input_cmds = (sizeof(input_cmds) / sizeof(cmd_func_matcher));

(void)num_input_cmds;
if (cmd_name == NULL)
{
/* if no command lines, return */
return (NULL);
}
/* The matcher loop*/
for (i = 0; input_cmds[i].comd; i++)
{
/* matches the user command with the ones in the list */
if (_strcmp(cmd_name, input_cmds[i].comd) == 0)
return (&input_cmds[i]);
}

return (NULL);
}


/**
 * execute_user_command - commands executer
 * @cmd: given command
 * @args: given argumments
 *
 * Return: NONE'*/

void execute_user_command(cmd_func_matcher *cmd, char **args)
{
cmd->command_func(args);
}

/**
 * shell_luncher - Executes commands in the shell
 * @args: given args
 * @bin_path: the given  binary path
 * @argv: main argumments array
 *
 * Retrun: NONE.
*/

void shell_luncher(char **args, char *bin_path, char *argv[])
{
int stat, exit_stat = 0;
pid_t PID;
/* fork will help us run a new proccess */
PID = fork();

if (exit_stat < 0)
return;
/* run command line as child (execvp) */
if (PID == 0)
{
if (execve(bin_path, args, environ) == -1)
{
perror(argv[0]);
exit(EXIT_FAILURE);
}
}
/* check if fork failed */
else if (PID < 0)
{

perror("fork");
exit(EXIT_FAILURE);
}
else
{
/* pause while chile process in working */
do {
/* Wait until the child process is done (our shell will wait) */
waitpid(PID, &stat, WUNTRACED);
}  while (!WIFEXITED(stat) && !WIFSIGNALED(stat));
exit_stat = WEXITSTATUS(stat);
}
}


/**
 * build_bin_path - full path to binary bulder
 * @cmd_name: given command name
 *
 * Return: the command on success, or NULL
*/

char *build_bin_path(char *cmd_name)
{
/* Get path */
char *path = getenv("PATH"), *path_cpy = strdup(path),
*path_dir = _strtok(path_cpy, ":"),
*binary_cmd = malloc(sizeof(char *) * BUFF_SIZE);
/* Error handling */
if (path == NULL)
{
perror("Error: PATH environment variable not set");
return (NULL);
}
if (path_cpy == NULL)
{
perror("Error: strdup failed");
return (NULL);
}
if (binary_cmd == NULL)
{
perror("Error: malloc failed");
free(path_cpy);
return (NULL);
}
/* save and return the binary command */
while (path_dir != NULL)
{
_strcpy(binary_cmd, path_dir);
_strcat(binary_cmd, "/");
_strcat(binary_cmd, cmd_name);
if (access(binary_cmd, X_OK) == 0)
{
free(path_cpy);
return (binary_cmd);
}
path_dir = _strtok(NULL, ":");
}
free(path_cpy);
return (binary_cmd);
}

/**
 * command_executer - Executes all the commands that the user enters
 * @args: given argumments
 * @argv: given argumments from the main
 *
 * Return: NONE
*/

void command_executer(char **args, char *argv[])
{
cmd_func_matcher *cmd;
char *binary_path = NULL;

if (args[0] == NULL)
{
return;
}
/* lunch '/' on shell if incountered */
if (args[0][0] == '/')
{
shell_luncher(args, args[0], argv);
return;
}
/* get the Unix command inputed  */
cmd = find_cmd(args[0]);

if (cmd != NULL)
{
execute_user_command(cmd, args);
return;
}
/* set the binary path */
binary_path = build_bin_path(args[0]);
/* lunch the shell */
shell_luncher(args, binary_path, argv);

free(binary_path);
binary_path = NULL;
}
