#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

int main(int argc, char **argv) {

  list *l = new_list(sizeof(int));

  for (int i = 0; i < 10; i++) {
    push_list(l, &i);
  }

  for (int i = 0; i < l->len; i++) {
    int *val = get_list(l, i);
    printf("l[%d]: %d\n", i, *val);
  }

  int *val = pop_list(l);
  printf("Popped value: %d\n", *val);

  return 0;
}
