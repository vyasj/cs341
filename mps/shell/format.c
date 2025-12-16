#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "format.h"

void prompt() {
  char* buf = malloc(64);
  buf = getcwd(buf, 64);
  pid_t pid = getpid();
  printf("(pid=%d) %s$ ", pid, buf);
}
