#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "shell.h"

int main(int argc, char **argv) {
  // Set resource limits for number of processes
  // because I do not trust myself to not fork bomb
  struct rlimit rlim;
  rlim.rlim_cur = 100;
  rlim.rlim_max = 250;
  if (setrlimit(RLIMIT_NPROC, &rlim) != 0) {
    exit(0);
  }

  // Read flag arguments
  int save_history = 0;
  FILE *fd;
  if (argc > 3) {
    fprintf(stderr, "Only one flag accepted, either -f or -h.\n");
    return -1;
  } else {
    if (argc == 3) {
      if (strcmp(argv[1], "-f") == 0) {
        // execute file
      } else if (strcmp(argv[1], "-h") == 0) {
        // load history, append new commands to file
      } else {
        fprintf(stderr, "Error: unrecognized flags. Use either -f or -h.\n");
        return -1;
      }
    }
  }
  
  return 0;
}