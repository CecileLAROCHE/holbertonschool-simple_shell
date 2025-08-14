#ifndef SHELL_H
#define SHELL_H

/*librairie utile*/
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Variables d'environnement */
extern char **environ;

/*prototypes utilisés*/
int main(__attribute__((unused)) int argc, char **argv);
char *read_line(void);
int process_command(char *line, char *argv[], int *exit_status);
char *_getenv(const char *name);

#endif

