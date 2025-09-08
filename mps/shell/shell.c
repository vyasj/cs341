#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "shell.h"

void load_file(char *flag, char *filename) {
  if (strcmp(flag, "-h") == 0) {
    printf("history file:%s\n", filename);
    // TODO: implement history
  }
  if (strcmp(flag, "-f") == 0) {
    printf("input file:%s\n", filename);
    // TODO: implement file
  }
}

void prompt_input() {
  pid_t pid = fork();
  if (pid == 0) {
    // in the child process
    execl("/bin/pwd", "/bin/pwd", NULL);
    exit(1);
  } else {
    // in the parent process
    printf("(pid=%d)", getpid());
    int wstatus;
    waitpid(pid, &wstatus, 0);
  }
}
