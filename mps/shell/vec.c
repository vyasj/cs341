#include "vec.h"

int INITIAL_CAPACITY = 8;

vector* new_vec(size_t e_size) {
	vector *vec = malloc(sizeof(vector));
	vec->len = 0;
	vec->size = e_size;
	vec->cap = INITIAL_CAPACITY;
	vec->data = malloc(INITIAL_CAPACITY * e_size);
	return vec;
}

void free_vec(vector *vec) {
	if (!vec) {
		printf("Vector is null. Call new_vec() to initialize\n");
		return;
	}
	free(vec->data);
	free(vec);
}

void push_vec(vector *vec, const void *e) {
	if (!vec) {
		printf("Vector is null. Call new_vec() to initialize.\n");
		return;
	}
	if (vec->len + 1 > vec->cap) {
		vec->cap *= 2;
		vec->data = realloc(vec->data, vec->cap);
	}
	void *ptr = vec->data + (vec->size * vec->len);
	ptr = memcpy(ptr, e, vec->size);
	vec->len++;
}

void *get_vec(vector *vec, size_t idx) {
	if (!vec || vec->len == 0) {
		printf("Vector is null or has no elements. Call new_vec() to initialize.\n");
	}
	return vec->data + (idx * vec->size);
}