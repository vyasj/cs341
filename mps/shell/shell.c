#include <string.h>
#include <stdio.h>

#include "shell.h"

void start_shell(char *flag, char *filename) {
  if (strcmp(flag, "-h") == 0) {
    printf("history file:%s\n", filename);
    // TODO: implement history
  }
  if (strcmp(flag, "-f") == 0) {
    printf("input file:%s\n", filename);
    // TODO: implement file
  }
}

void prompt_input(int pid, char *path) {
  printf("(pid=%d)%s", pid, path);
}
