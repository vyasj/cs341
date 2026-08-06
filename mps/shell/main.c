//#include <sys/time.h>
//#include <sys/resource.h>
//#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#include "shell.h"

volatile sig_atomic_t sigint_rcvd = 0;

static void handler(int sig) {
  if (sig == SIGINT) {
    sigint_rcvd = 1;
  }
}

int main(int argc, char **argv) {

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

  // 2. Start while loop until SIGINT, "exit", or EOF
  shell *sh = spawn_shell();

  struct sigaction sa;
  sa.sa_handler = handler;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = 0;
  sigaction(SIGINT, &sa, NULL);
  
  while (1) {
    // 3. Prompt user for input
    char *input = prompt(sh);

    if (sigint_rcvd) {
      printf("sigint received\n");
      break;
    }

    if (strcmp(input, "exit") == 0) {
      break;
    }
  }

  // 4. Scan if input is custom command
  // 5. Fork a process to run the command
  // 6. Execute the command
  // 7. Wait until the process completes
  
  return 0;
}