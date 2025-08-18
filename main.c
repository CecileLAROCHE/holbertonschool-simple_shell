#include "Shell.h"

int process_command(char *line, char *argv[], int cmd_count, int *exit_status);
char *read_line(void);

int main(int argc __attribute__((unused)), char *argv[])
{
	char *line = NULL;
	int exit_status = 0;
	int should_exit;
	int cmd_count = 0;

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
				printf("Bye bye\n");
			break;
		}

		cmd_count++;

		should_exit = process_command(line, argv, cmd_count, &exit_status);

		free(line);

		if (should_exit)
			return (exit_status);
	}
	return (exit_status);
}
