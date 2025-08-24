#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
  pid_t id;
  int status;

  while (--argc && (id = fork())) {
    waitpid(id, &status, 0);
  }

  printf("%d:%s\n", argc, argv[argc]);

  return 0;
}
