#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>

// prompt user for input
char* prompt();

// -f flag used, load file and run all commands
void read_file(FILE *fd);

// -h flag used, output history to file
void write_file(FILE *fd, char* cmd);

// fork-exec-wait cycle
int cycle(char* cmd);

#endif
