#include "Shell.h"

/**
 * process_command - Traite et exécute une commande entrée par l'utilisateur.
 *
 * Cette fonction analyse la ligne de commande donnée, sépare les arguments
 * et exécute la commande correspondante. Elle gère également les commandes
 * intégrées (built-ins), les erreurs d'exécution, et met à jour le statut
 * de sortie.
 *
 * @line: La ligne de commande à traiter.
 * @argv: Un tableau de chaînes de caractères pour stocker les arguments.
 * @cmd_count: Le nombre de commandes déjà traitées (utile pour les messages d'erreur).
 * @exit_status: Pointeur vers la variable stockant le statut de sortie du shell.
 *
 * Return: 0 si la commande a été traitée avec succès, ou un code d'erreur sinon.
 */

int process_command(char *line, char *argv[], int cmd_count, int *exit_status)
{
	char *args[64];
	int index = 0;
	char *token = strtok(line, " \t\r\n");
	char *cmd_path = NULL;

	/* Découpe la ligne en tokens (arguments), séparés par des espaces ou tabulations */
	while (token != NULL && index < 63)
	{
		args[index++] = token;
		token = strtok(NULL, " \t\r\n");
	}
	args[index] = NULL;

	/* Si aucune commande n'est entrée, on ne fait rien */
	if (args[0] == NULL)
		return (0);

	/* Commande intégrée "exit" */
	if (strcmp(args[0], "exit") == 0)
		return (1);

	/* Commande intégrée "env" pour afficher les variables d'environnement */
	if (strcmp(args[0], "env") == 0)
	{
		print_env();
		return (0);
	}
	/* Si la commande contient un '/' quelque part, c’est un chemin (absolu ou relatif) */
	if (strchr(args[0], '/'))
		{
		if (access(args[0], X_OK) == 0)
			cmd_path = strdup(args[0]);
		else
		{
			printf("%s: %d: %s: not found\n", argv[0], cmd_count, args[0]);
			return (127);
		}
	}
	else
	{
		/* Recherche la commande dans le PATH */
		cmd_path = find_in_path(args[0]);
		if (cmd_path == NULL)
		{
			printf("%s: %d: %s: not found\n", argv[0], cmd_count, args[0]);
			return (127);
		}
	}

	/* Exécute la commande et libère la mémoire allouée */
	execute_command(cmd_path, args, argv[0], exit_status);
	free(cmd_path);
	return (0);
}
