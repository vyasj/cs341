#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	size_t len;  // number of elements in the vec
	size_t size; // size of each element in bytes
	size_t cap;  // maximum capacity of the vec in bytes
	void *data;  // pointer to the array of elements
} vector;

vector *new_vec(size_t elem_size);

void free_vec(vector *vec);

void push_vec(vector *vec, const void *e);

void *get_vec(vector *vec, size_t idx);