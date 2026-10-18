#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>
#include <unistd.h>

#include "vec.h"

typedef struct {
    vector *proc_ids;   // vector of process ids currently running in the shell
    FILE *history;      // file pointer to history file
    char *dir;          // operating directory of the shell
} shell;

// create an empty shell
shell *spawn_shell();

// prompt user for input
char* prompt(shell *sh);

// fork-exec-wait cycle
void cycle(shell *sh);

#endif