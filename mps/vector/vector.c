#include <stdio.h>
#include <stdlib.h>

typedef struct {
	size_t len; // number of elements in the vec
	size_t size; // size of the vec in bytes
	size_t cap; // maximum capacity of the vec in bytes
	int *data; // list of addresses to each element in the vec
} vector;

void init_vector(vector *vec) {
	vec->len = 0;
	vec->size = 0;
	vec->cap = sizeof(int*);
	vec->data = malloc(sizeof(int*));
}

void free_vector(vector *vec) {
	free(vec->data);
}

void push_vector(vector *vec, void *val) {
	vec->len++;
	vec->size = vec->size + sizeof(int);

	if (vec->len > vec->cap) {
		vec->cap = vec->cap * 2;
		vec->data = realloc(vec->data, vec->cap);
	}

	int **addr = &val;
	vec->data[vec->len-1] = *addr;
}

int main() {
	vector *vec;
	init_vector(vec);

	int val = 7;
	push_vector(vec, &val);

	free_vector(vec);
	
	return 0;
}
