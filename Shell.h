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
char *read_line(void);
int process_command(char *line, char *argv[], int *exit_status);
int _strcmp(const char *s1, const char *s2);

#endif
