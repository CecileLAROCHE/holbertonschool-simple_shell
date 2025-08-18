#include "Shell.h"

/**
 * print_env - Affiche toutes les variables d'environnement
 *
 * Parcourt la variable globale environ et affiche
 * chaque variable d'environnement suivie d'un saut de ligne.
 */

void print_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
