#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "format.h"

char* prompt(char* input) {
  char* buf = malloc(64);
  buf = getcwd(buf, 64);
  pid_t pid = getpid();
  printf("(pid=%d) %s$ ", pid, buf);
  free(buf);
  scanf(" %s", input);
  return input;
}
