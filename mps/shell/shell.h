#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>
#include <unistd.h>

#include "vec.h"

typedef struct {
    vector *proc_ids;   // vector of process ids currently running in the shell
    FILE *history;      // file pointer to history file
} shell;

// prompt user for input
char* prompt();

#endif