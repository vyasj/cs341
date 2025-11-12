#include <stdlib.h>
#include <string.h>

#include "list.h"

list* new_list(int e_size) {
  list *l = malloc(sizeof(list));
  l->size = e_size;
  l->cap = 8;
  l->len = 0;
  l->data = malloc(8 * e_size);
  return l;
}

void free_list(list *l) {
  if (!l) {
    return;
  }
  free(l->data);
  free(l);
}

void push_list(list *l, void *e) {
  if (!l || !e) {
    return;
  }
  if (l->len + 1 > l->cap) {
    l->cap = 2 * l->cap;
    l->data = realloc(l->data, l->size * l->cap);
  }
  void *ptr = l->data + (l->size * l->len);
  ptr = memcpy(ptr, e, l->size);
  l->len++;
}

void *get_list(list *l, int idx) {
  return l->data + (l->size * idx);
}

void set_list(list *l, int idx, void *val) {
  void *ptr = l->data + (l->size * idx);
  ptr = memcpy(ptr, val, l->size);
}

// void *pop_list(list *l) {
//   void *end;
//   if (!l) {
//     return end;
//   }
//   if (l->len - 1 < l->cap / 2) {
//     l->cap = l->cap / 2;
//     l->data = realloc(l->data, l->size * l->cap);
//   }
//   end = memcpy(end, l->data + (l->size * (l->len - 1)), l->size);
//   l->len--;
//   return end;
// }
