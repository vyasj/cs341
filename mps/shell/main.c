#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "shell.h"
#include "format.h"
#include "list.h"

int main(int argc, char **argv) {
  // Set resource limits for number of processes
  // because I do not trust myself to not fork bomb
  struct rlimit rlim;
  rlim.rlim_cur = 100;
  rlim.rlim_max = 250;
  if (setrlimit(RLIMIT_NPROC, &rlim) != 0) {
    exit(0);
  }

  int save_history = 0;

  while (1) {
    // if SIGINT, exit loop
    char* buf = malloc(256);
    buf = prompt(buf);
    free(buf);
  }

  // output history file if specified
  
  return 0;
}
