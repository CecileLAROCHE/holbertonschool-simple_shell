#include "Shell.h"


int process_command(char *line, char *argv[], int cmd_count, int *exit_status)
{
	char *args[64];
	int index = 0;
	char *token = strtok(line, " \t\r\n");
	char *cmd_path = NULL;

	while (token != NULL && index < 63)
	{
		args[index++] = token;
		token = strtok(NULL, " \t\r\n");
	}
	args[index] = NULL;

	if (args[0] == NULL)
		return (0);

	if (strcmp(args[0], "exit") == 0)
		return (1);

	if (strcmp(args[0], "env") == 0)
	{
		print_env();
		return (0);
	}

	if (args[0][0] == '/' || (args[0][0] == '.' && args[0][1] == '/'))
	{
		if (access(args[0], X_OK) == 0)
			cmd_path = strdup(args[0]);
		else
		{
			printf("%s: %d: %s: command not found\n", argv[0], cmd_count, args[0]);
			return (0);
		}
	}
	else
	{
		cmd_path = find_in_path(args[0]);
		if (cmd_path == NULL)
		{
			printf("%s: %d: %s: command not found\n", argv[0], cmd_count, args[0]);
			return (0);
		}
	}

	execute_command(cmd_path, args, argv[0], exit_status);
	free(cmd_path);
	return (0);
}
