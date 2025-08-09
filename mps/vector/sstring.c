#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  char *letters;
  size_t len;
} sstring;

sstring make_sstring(char *word) {
  sstring str;
}

int main() {
  char *name = "hello world\0";

  printf("%s\n", name);
  printf("sizeof name: %zu\n", sizeof(name));
  
  return 0;
}
