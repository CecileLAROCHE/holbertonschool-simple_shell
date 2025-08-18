#include "Shell.h"

/**
 * find_in_path - Find a command in the system PATH
 * @command: Command to find
 *
 * Return: Full path to the command if found, NULL otherwise
 */

char *find_in_path(const char *command)
{
	char *path = _getenv("PATH");
	char *path_copy;
	char *dir;
	char full_path[1024];
	char *result;

	/*verifie l'existance du chemin*/
	if (path == NULL)
		return (NULL);

/*Récupérer la variable PATH*/
	path_copy = strdup(path);

	/*verifie l'existance de la vatiable path_copy*/
	if (path_copy == NULL)
		return (NULL);

/*Découper PATH en dossiers*/
	dir = strtok(path_copy, ":");
/*Construire le chemin complet pour chaque dossier*/
	while (dir != NULL)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
/*Vérifier si le fichier existe et est exécutable*/
		if (access(full_path, X_OK) == 0)
		{
			result = (strdup(full_path));
			free(path_copy);
			return (result);
		}
		dir = strtok(NULL, ":");
	}
	/*Libération mémoire*/
	free(path_copy);
	/*Si aucune correspondance, retourner NULL*/
	return (NULL);
}

