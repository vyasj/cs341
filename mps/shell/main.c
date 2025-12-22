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

  char* history_file;

  if (argc > 3) {
    fprintf(stderr, "Only one flag accepted, either -f or -h.\n");
    return -1;
  } else {
    if (argc <= 2) {
      fprintf(stderr, "Error: invalid number of operands provided.\n");
      return -1;
    }
    if (strcmp(argv[1], "-f") == 0) {
      load_file(argv[2]);
    } else if (strcmp(argv[1], "-h") == 0) {
      printf("opening file %s\n", argv[2]);
      history_file = strcpy(history_file, argv[2]);
      // open file with filename and save history there after exiting
    } else {
      fprintf(stderr, "Error: unrecognized flags. Use either -f or -h.\n");
      return -1;
    }
  }
  
  while (1) {
    // if SIGINT, exit loop
    char* buf = malloc(256);
    buf = prompt(buf);

    if (strcmp(buf, "exit") == 0) {
      free(buf);
      break;
    }

    cycle(buf);
    
    free(buf);
  }

  // output history file if specified
  
  return 0;
}
