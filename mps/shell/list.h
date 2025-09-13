#ifndef LIST_H_
#define LIST_H_

// struct definition of list
typedef struct {
  int len;
  int cap;
  int size;
  void* data;
} list;

// create a new list
list* new_list(int e_size);

// free the list
void free_list(list *l);

// append to the list
void push_list(list *l, void *e);

// fetch from the list at index idx
void *get_list(list *l, int idx);

// remove from the list at index idx
void pop_list(list *l, int idx);

#endif
