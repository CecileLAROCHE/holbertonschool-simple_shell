#include "Shell.h"

/**
 * _getenv - Récupère la valeur d'une variable d'environnement
 * @name: Nom de la variable d'environnement à chercher
 *
 * Parcourt la liste des variables d'environnement pour trouver
 * celle correspondant à @name et retourne sa valeur (après le '=').
 *
 * Return: Une chaîne allouée dynamiquement
 * contenant la valeur de la variable,
 *         ou NULL si la variable n'existe pas.
 */

char *_getenv(const char *name)
{
	int i = 0;
	size_t len = strlen(name);

	while (environ[i] != NULL)
	{

		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
		{

			return (strdup(&environ[i][len + 1]));
		}
		i++;
	}
	free(strdup(&environ[i][len + 1]));
	return (NULL);
}
