//#include <sys/time.h>
//#include <sys/resource.h>
//#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "shell.h"

int main(int argc, char **argv) {
  // Set resource limits for number of processes
  // because I do not trust myself to not fork bomb
//   struct rlimit rlim;
//   rlim.rlim_cur = 100;
//   rlim.rlim_max = 250;
//   if (setrlimit(RLIMIT_NPROC, &rlim) != 0) {
//     exit(0);
//   }

  // 1. Read flag arguments
  // 2. Start while loop until SIGINT
  // 3. Prompt user for input
  // 4. Scan if input is custom command
  // 5. Fork a process to run the command
  // 6. Execute the command
  // 7. Wait until the process completes

  shell *sh = spawn_shell();

  while (1) {
    char *input = prompt(sh);
  }
  
  return 0;
}