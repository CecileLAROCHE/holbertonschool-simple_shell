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

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("My simple_shell> ");
			fflush(stdout);
		}

		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				printf("Break\n");
			break;
		}

		should_exit = process_command(line, argv, &exit_status);

		free(line);

		if (should_exit)
		{
			return (exit_status);
		}
	}
	return (exit_status);
}

