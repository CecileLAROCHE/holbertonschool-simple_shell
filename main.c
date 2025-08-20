#include "Shell.h"

/**
 * main - Point d'entrée principal du shell.
 *
 * Description: Cette fonction implémente
 * une boucle de lecture, d'analyse et
 * d'exécution de commandes. Elle gère l'affichage de l'invite
 * en mode interactif, appelle read_line pour lire la commande
 * de l'utilisateur, puis process_command pour l'exécuter.
 * Si la commande "exit" est détectée, le shell se termine.
 *
 * @argc: Nombre d'arguments passés au programme (non utilisé).
 * @argv: Tableau des arguments passés au programme.
 *
 * Return: exit_status (0 par défaut ou selon la commande "exit").
 */

int main(int argc __attribute__((unused)), char *argv[])
{
	char *line = NULL;
	int exit_status = 0;
	int should_exit;
	int cmd_count = 0;
	int use_color = isatty(STDOUT_FILENO); /* Active couleur si sortie = terminal */

	/* Boucle principale du shell */
	while (1)
	{
		/* Affiche l'invite si le shell est en mode interactif */
		if (isatty(STDIN_FILENO))
		{
			if (use_color)
				printf("\033[1;34mMy simple_shell>\033[0m "); /* bleu gras */
			else
				printf("My simple_shell> ");
			fflush(stdout);
		}

		/* Lit une ligne de l'entrée standard */
		line = read_line();
		if (line == NULL)
		{
			/* Si EOF est atteint, afficher un message si en mode interactif */
			if (isatty(STDIN_FILENO))
				printf("Bye bye\n");
			break;
		}

		cmd_count++; /* Incrémente le compteur de commandes exécutées */

		/* Traite la commande lue et vérifie si on doit quitter le shell */
		should_exit = process_command(line, argv, cmd_count, &exit_status);

		free(line); /* Libère la mémoire allouée pour la ligne */

		/* Si la commande était "exit", quitte le shell avec le bon code */
		if (should_exit)
			return (exit_status);
	}

	return (exit_status); /* Retourne le statut final après la boucle */
}
