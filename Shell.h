#ifndef SHELL_H
#define SHELL_H

/*librairie utile*/
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

/* Variables d'environnement */
extern char **environ;

/*prototypes utilisés*/
int main(__attribute__((unused)) int argc, char **argv);
char *read_line(void);
int process_command(char *line, char *argv[], int cmd_count, int *exit_status);
char *_getenv(const char *name);
char *find_in_path(const char *command);
void execute_command(char *cmd_path, char **args, const char *shell_n,
	int *exit_stat);

#endif

