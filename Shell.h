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
char *find_in_path(const char *command);
char *_getenv(const char *name);
void execute_command(char *cmd_path, char **args, const char *shell_n,
int *exit_stat);
int main(int argc __attribute__((unused)), char *argv[]);
void print_env(void);
int process_command(char *line, char *argv[], int cmd_count, int *exit_status);
char *read_line(void);


#endif

