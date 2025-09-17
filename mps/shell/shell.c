#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "shell.h"

void load_file(char *flag, char *filename) {
  if (strcmp(flag, "-h") == 0) {
    printf("history file:%s\n", filename);
    // TODO: implement history
  }
  if (strcmp(flag, "-f") == 0) {
    printf("input file:%s\n", filename);
    // TODO: implement file
  }
}

