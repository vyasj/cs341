#include <string.h>
#include <stdio.h>

#include "shell.h"

void start_shell(char *flag, char *filename) {
  if (strcmp(flag, "-h")) {
    printf("history file:%s\n", filename);
    // TODO: implement history
  }
  if (strcmp(flag, "-f")) {
    printf("input file:%s\n", filename);
    // TODO: implement file
  }
}

void prompt_input(int pid, char *path) {
  printf("(pid=%d)%s", pid, path);
}
