#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "shell.h"

char* prompt() {
  char* buf = malloc(64);
  buf = getcwd(buf, 64);
  pid_t pid = getpid();
  printf("(pid=%d) %s$ ", pid, buf);

  char *line = NULL;
  size_t size = 0;
  ssize_t nread;
  nread = getline(&line, &size, stdin);

  free(buf);
  return line;
}