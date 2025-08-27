#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>

#include "format.h"

int main(int argc, char **argv) {
  // Set resource limits for number of processes
  // because I do not trust myself to not fork bomb
  struct rlimit rlim;
  rlim.rlim_cur = 100;
  rlim.rlim_max = 250;
  if (setrlimit(RLIMIT_NPROC, &rlim) != 0) {
    exit(0);
  }

  arg_error(argc);

  return 0;
}
