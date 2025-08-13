#include "Shell.h"

/**
 * main - Runs a simple shell that reads and prints user input
 *
 * This program continuously prompts the user for input, reads a line
 * from standard input, and prints the command entered by the user until
 * EOF (Ctrl+D) is encountered.
 * Return: Always 0 (Success)
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{

		if (isatty(STDIN_FILENO))
			printf("$ ");

		nread = getline(&line, &len, stdin);

		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}

		line[strcspn(line, "\n")] = '\0';

		printf("Commande : %s\n", line);

		if (should_exit)
		{
			return (exit_status);
		}
	}
	return (exit_status);
}
