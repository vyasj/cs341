#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

#include "shell.h"

shell *spawn_shell() {
  char* buf = malloc(64);
  buf = getcwd(buf, 64);

  shell *sh = malloc(sizeof(shell));
  sh->proc_ids = new_vec(sizeof(pid_t));
  sh->history = tmpfile();
  sh->dir = buf;

  return sh;
}

char* prompt(shell *sh) {
  pid_t pid = getpid();
  printf("(pid=%d) %s$ ", pid, sh->dir);

  char *line = NULL;
  size_t size = 0;
  ssize_t nread;
  nread = getline(&line, &size, stdin);
  
  return line;
}