#include "Shell.h"

/**
 * read_line - Reads a line from standard input
 *
 * This function reads a line from standard input, dynamically allocating
 * memory for the line. It removes the newline character at the end if present.
 * Returns NULL on EOF or error.
 *
 * Return: Pointer to the line read, or NULL on EOF/error
 */

char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int i;

	read = getline(&line, &len, stdin);

/*Gérer la fin de saisie (EOF / Ctrl+D)*/
	if (read == -1)
	{
		free(line);
		return (NULL);
	}
/*Suppression du \n final*/
	for (i = 0; line[i] != '\0'; i++)
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
			break;
		}
	}
/*Retour de la ligne lue*/
	return (line);
}

