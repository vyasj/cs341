#include <stdio.h>
#include <stdlib.h>

typedef struct {
	size_t len;  // number of elements in the vec
	size_t size; // size of vec in bytes
	size_t cap;  // maximum capacity of the vec in bytes
	void *data;  // pointer to the array of elements
} vector;

void init_vec(vector *vec) {
	vec->len = 0;
	vec->size = 0;
	vec->cap = sizeof(void*);
	vec->data = malloc(sizeof(void*));
}

void free_vec(vector *vec) {
	free(vec->data);
}

void push_vec(vector *vec, void *val) {
	if (vec->size + sizeof(val) > vec->cap) {
		vec->cap = 2 * vec->cap;
		vec->data = realloc(vec->data, vec->cap);
	}

	vec->size = vec->size + sizeof(val);
	vec->data[vec->len] = val;
	vec->len++;
}

int main() {
	vector *vec;
	init_vec(vec);

	return 0;
}
