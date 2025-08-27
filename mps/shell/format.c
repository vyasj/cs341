#include <stdio.h>

#include "format.h"

int arg_error(int n_args) {
  if (n_args != 1 && n_args != 3) {
    printf("The only acceptable arguments are -h and -f, cannot accept %d arguments.\n", n_args-1);
    return 1;
  } 
  return 0;
}
