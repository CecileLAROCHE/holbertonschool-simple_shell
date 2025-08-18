#include "Shell.h"

/**
 * execute_command - Exécute une commande en créant un processus fils
 * @cmd_path: Chemin complet vers la commande à exécuter
 * @args: Tableau d'arguments pour la commande (doit être NULL-terminated)
 * @shell_n: Nom du shell (pour afficher les messages d'erreur)
 * @exit_stat: Pointeur vers la variable qui contiendra le statut de sortie
 *
 * Cette fonction crée un processus fils avec fork(), puis
 * dans le fils, elle exécute la commande avec execve().
 * Le processus parent attend la fin du fils et récupère son statut.
 */

void execute_command(char *cmd_path, char **args,
const char *shell_n, int *exit_stat)
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
}
