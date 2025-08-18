#include "Shell.h"


void execute_command(char *cmd_path, char **args, const char *shell_n, int *exit_stat)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid < 0)
	{
		perror("fork");
		*exit_stat = 1;
		return;
	}

	if (pid == 0)
	{
		if (execve(cmd_path, args, environ) == -1)
		{
			perror(shell_n);
			exit(127);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			*exit_stat = WEXITSTATUS(status);
		else
			*exit_stat = 1;
	}
	free(cmd_path);
}
