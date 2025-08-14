#include "Shell.h"

/**
 * process_command - Process a command line
 * @line: Input command line
 * @argv: Program arguments
 * @cmd_count: Command counter
 * @exit_status: Pointer to exit status
 *
 * Return: 1 to exit shell, 0 to continue
 */
int process_command(char *line, char *argv[], int cmd_count, int *exit_status)
{
	char *args[64];
	int index = 0;
	char *token = strtok(line, "\t\r\n");

	while (token != NULL && index < 63)
	{
		args[index++] = token;
		token = strtok(NULL, "\t\r\n");
	}

	args[index] = NULL;

	if (args[0] == NULL)
	{
		return (0);
	}

	if (strcmp(args[0], "exit") == 0)
	{
		return (1);
	}
}

