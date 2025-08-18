#include "Shell.h"

/**
 * find_in_path - Cherche une commande dans la variable d'environnement PATH
 * @command: La commande à rechercher
 *
 * Cette fonction récupère la variable PATH, la duplique,
 * puis parcourt chaque dossier séparé par ':' pour chercher
 * si la commande existe et est exécutable.
 *
 * Return: Un pointeur vers le chemin complet de la commande s'il est trouvé,
 *         sinon NULL.
 *
 * Description des flags :
 * - X_OK : vérifie si le fichier est exécutable.
 */

char *find_in_path(const char *command)
{
	char *path = _getenv("PATH");
	char *path_copy, *dir, full_path[1024], *result;

	if (path == NULL)
		return (NULL);

	path_copy = strdup(path);
	free(path);  /* Libération ici, car _getenv fait strdup */

	if (path_copy == NULL)
		return (NULL);

	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
		if (access(full_path, X_OK) == 0)
		{
			result = strdup(full_path);
			free(path_copy);
			return (result);
		}
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
