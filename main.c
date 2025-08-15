#include "Shell.h"

/**
 * main - Runs a simple shell that reads and prints user input
 *
 * This program continuously prompts the user for input, reads a line
 * from standard input, and prints the command entered by the user until
 * EOF (Ctrl+D) is encountered.
 * @argc: Argument count
 * @argv: Argument value
 * Return: Always 0 (Success)
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	char *line = NULL;
	int exit_status = 0;
	int should_exit;

	/* Boucle principale, gère l’affichage du prompt et la lecture ligne */
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("My simple_shell> ");
			fflush(stdout);
		}

		/*La gestion de Ctrl+D (EOF) avec un break.*/
		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				printf("Bye bye\n");
			break;
		}

		/*Un appel à process_command() pour traiter la commande.*/
		should_exit = process_command(line, argv, cmd_count, &exit_status);


		printf("Commande : %s\n", line);

		/*La libération de la mémoire de line à chaque tour de boucle.*/
		free(line);


		if (should_exit)
		{
			return (exit_status);
		}
	}
	return (exit_status);
}

