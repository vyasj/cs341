#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int INITIAL_CAPACITY;

typedef struct {
	size_t len;  // number of elements in the vec
	size_t size; // size of each element in bytes
	size_t cap;  // maximum capacity of the vec in bytes
	void *data;  // pointer to the array of elements
} vector;

vector* new_vec(size_t e_size) {
	vector *vec = malloc(sizeof(vector));
	vec->len = 0;
	vec->size = e_size;
	vec->cap = INITIAL_CAPACITY;
	vec->data = malloc(INITIAL_CAPACITY * e_size);
	return vec;
}

void free_vec(vector *vec) {
	free(vec->data);
	free(vec);
}

void push_vec(vector *vec, const void *e) {
	if (vec->len + 1 > vec->cap) {
		vec->cap *= 2;
		vec->data = realloc(vec->data, vec->cap);
	}
	void *ptr = vec->data + vec->len;
	ptr = memcpy(ptr, e, vec->size);
	vec->len++;
}

void *get_vec(vector *vec, size_t idx) {
	void *ptr;
	ptr = memcpy(ptr, vec->data + idx, vec->size);
	return ptr;
}

int main() {
	INITIAL_CAPACITY = 8;
	vector *vec = new_vec(sizeof(int));

	int val = 7;
	push_vec(vec, &val);

	int val2 = 10;
	push_vec(vec, &val2);

	for (int i = 0; i < vec->len; i++) {
		void *e = get_vec(vec, i);
		printf("vec->data[%d] = %p\n", i, e);
	}
	
	return 0;
}
