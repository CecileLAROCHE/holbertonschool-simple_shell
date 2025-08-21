#include "Shell.h"

/**
 * read_line - Lit une ligne complète depuis l'entrée standard.
 *
 * Cette fonction alloue dynamiquement une mémoire pour lire une ligne
 * de texte depuis l'entrée standard (stdin) jusqu'à ce qu'un caractère
 * de nouvelle ligne soit rencontré ou que l'entrée soit terminée (EOF).
 * La mémoire retournée doit être libérée par l'appelant.
 *
 * Return: Un pointeur vers la ligne lue (incluant le '\n' si présent),
 *         ou NULL en cas d'erreur ou si EOF est atteint sans lecture.
 */

char *read_line(void)
{
	char *line = NULL;
	/*Pointeur vers la ligne lue initialisé à NULL, getline alloue la mémoire*/
	size_t len = 0;
	/* Taille initiale du tampon, 0 pour que getline la gère automatiquement */
	ssize_t read;
	/* Stocke le nombre de caractères lus ou -1 en cas d'erreur/EOF */
	int i; /* Variable de boucle pour parcourir la ligne */

	read = getline(&line, &len, stdin);
	/* Lecture d'une ligne depuis l'entrée standard (stdin) */

	/*Gérer la fin de saisie (EOF / Ctrl+D)*/
	if (read == -1) /* Si la lecture échoue (EOF ou erreur) */
	{
		free(line); /* Libération de la mémoire allouée à line */
		return (NULL); /* Retour de NULL pour signaler l'erreur */
	}
	/*Suppression du \n final*/
	for (i = 0; line[i] != '\0'; i++)
	/* Parcours de la ligne jusqu'au caractère nul */
	{
		if (line[i] == '\n') /* Si un saut de ligne est trouvé */
		{
			line[i] = '\0';
			/* Remplacement du saut de ligne par le caractère nul */
			break;
			/* Sortie de la boucle après modification */
		}
	}
	/*Retour de la ligne lue*/
	return (line);
	/* Retour du pointeur vers la ligne modifiée */
}
