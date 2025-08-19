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

	/* Création d'un nouveau processus enfant */
	pid = fork();

	/* Gestion de l'erreur lors du fork */
	if (pid < 0)
	{
		perror("fork");
		*exit_stat = 1;
		return;
	}

	/* Code exécuté uniquement dans le processus enfant */
	if (pid == 0)
	{
		/*
		 * Remplace le processus enfant par la commande spécifiée.
		 * execve charge et exécute le binaire à cmd_path avec les arguments args
		 * et l'environnement courant 'environ'.
		 */
		if (execve(cmd_path, args, environ) == -1)
		{
			/* Affiche un message d'erreur en cas d'échec */
			perror(shell_n);

			/*
			 * Termine le processus enfant avec le code 127,
			 * qui indique généralement une commande introuvable.
			 */
			exit(127);
		}
	}
	else
	{
		/* Code exécuté uniquement dans le processus parent */

		/*
		 * Attend la fin du processus enfant et récupère son statut.
		 * waitpid permet de bloquer le parent jusqu'à la fin de l'enfant.
		 */
		waitpid(pid, &status, 0);

		/* Vérifie si l'enfant s'est terminé normalement */
		if (WIFEXITED(status))
			*exit_stat = WEXITSTATUS(status); /* Récupère son code de sortie */
		else
			*exit_stat = 1; /* Si arrêt anormal, définit un code d'erreur */
	}
}
