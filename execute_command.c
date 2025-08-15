#include "Shell.h"
/**
 * execute_command - Execute a command with fork and execve
 * @cmd_path: Full path to the command
 * @args: Command arguments
 * @shell_n: Shell name
 * @exit_stat: Exit status pointer
 */
void execute_command(char *cmd_path, char **args, const char *shell_n,
	int *exit_stat)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid < 0) /*Le parent sait qui est l’enfant*/
	{
		perror("fork");
		*exit_stat = 1;
		return;
	}

	if (pid == 0) /* Processus enfant */
	{
		if (execve(cmd_path, args, environ) == -1)
		{
			perror(shell_n); /* ex: ./myshell: ls: No such file */
			exit(127);       /* code d'erreur standard pour commande non trouvée */
		}
	}
	else /* Processus parent */
	{
		waitpid(pid, &status, 0); /* Attend la fin du processus enfant */

		if (WIFEXITED(status))
			*exit_stat = WEXITSTATUS(status);
		else
			*exit_stat = 1;
	}
}

