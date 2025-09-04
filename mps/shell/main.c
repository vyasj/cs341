#include <sys/time.h>
#include <sys/resource.h>
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

  char *flag, *filename;
  if (argc == 1) {
    flag = "";
    filename = "";
  } else if (argc == 3) {
    flag = argv[1];
    filename = argv[2];
  } else {
    printf("Invalid number of flags. Check the README for details.\n");
    exit(1);
  }

  load_file(flag, filename);

  pid_t child = fork();
  if (child != 0) {
    prompt_input(child, "/test/path");
  }
  
  return 0;
}
