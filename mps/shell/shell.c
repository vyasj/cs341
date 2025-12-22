#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "shell.h"

void load_file(char *filename) {
  FILE *fp = fopen(filename, "r");
  char *line = NULL;
  size_t size = 0;
  ssize_t nread;

  while ((nread = getline(&line, &size, fp)) != -1) {
    printf("Read line of length %zd\n", nread);
    printf("Line:\n>\t%s\n", line);
    cycle(line);
  }

  free(line);
}

void write_cmd(char *filename, char* cmd) {
  FILE *fd = fopen(filename, "a");
}

int cycle(char* cmd) {
  // fork-exec-wait cycle
  return 0;
}
