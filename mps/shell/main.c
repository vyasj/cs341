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
  int c;
  char *ifile, *ofile;
  while ((c = getopt(argc, argv, "f:h:")) != -1) {
    switch (c) {
    case 'f':
      ifile = optarg;
      printf("Reading history file %s\n", ifile);
      break;
    case 'h':
      ofile = optarg;
      printf("Writing to history file %s\n", ofile);
      break;
    case ':':
      printf("Need an argument after the option %c\n", c);
      break;
    case '?':
      printf("Error: Incorrect option flag use. Supported options are:\n\t-f\t\tInput history file to read\n\t-h\t\tOutput history file to write to\n");
      break;
    }
  }
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