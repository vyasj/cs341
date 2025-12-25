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

void read_file(FILE *fd) {
  char *line = NULL;
  size_t size = 0;
  ssize_t nread;

  while ((nread = getline(&line, &size, fd)) != -1) {
    printf("Read line of length %zd\n", nread);
    printf("Line:\n>\t%s\n", line);
    cycle(line);
  }

  free(line);
}

void write_file(FILE *fd, char* cmd) {
  int success = fputs(cmd, fd);
  if (!success) {
    fprintf(stderr, "Error writing to file");
  }
}

int cycle(char* cmd) {
  // fork-exec-wait cycle
  return 0;
}
