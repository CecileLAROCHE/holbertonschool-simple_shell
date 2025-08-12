#ifndef SHELL_H
#define SHELL_H

/*librairie utile*/
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*prototypes utilisés*/
char *read_line(void);
int process_command(char *line, char *argv[], int cmd_count, int *exit_status);

#endif
