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

	/* Si PATH n'existe pas, on ne peut pas chercher */
	if (path == NULL)
		return (NULL);

	/* Duplique la chaîne PATH car strtok modifie la chaîne */
	path_copy = strdup(path);

	/* Libère la chaîne allouée par _getenv */
	free(path);

	/* Vérifie que la duplication a réussi */
	if (path_copy == NULL)
		return (NULL);

	/* Découpe path_copy en répertoires, séparés par ':' */
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		/* Construit le chemin complet vers la commande dans ce répertoire */
		snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
		/* Vérifie si ce fichier est exécutable */
		if (access(full_path, X_OK) == 0)
		{
			/* Duplique le chemin complet pour le retourner */
			result = strdup(full_path);

			/* Libère la copie de PATH */
			free(path_copy);

			return (result);
		}
		/* Passe au répertoire suivant */
		dir = strtok(NULL, ":");
	}
	/* Commande non trouvée dans aucun répertoire du PATH */
	free(path_copy);
	return (NULL);
}
