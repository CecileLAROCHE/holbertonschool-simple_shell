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
	char *cmd_path;

	while (token != NULL && index < 63)
	{
		args[index++] = token;
		token = strtok(NULL, "\t\r\n");
	}

	args[index] = NULL;

	/*si ligne vide*/
	if (args[0] == NULL)
	{
		return (0);
	}

	/*si exit*/
	if (strcmp(args[0], "exit") == 0)
	{
		return (1);
	}

	/* recharcghe dans path*/
	cmd_path = find_in_path(args[0]);
	if (cmd_path != NULL)
	{
		execute_command(cmd_path, args, argv[0], exit_status);
		free(cmd_path);
	}
	else
	{
		printf("%s: command not found\n", args[0]);
	}
	return (0);
}

