#include <stdio.h>
#include <stdlib.h>

typedef struct {
	size_t len;
	size_t size;
	void *data;
} vector;

vector init_vector() {
	vector vec;

	vec.len = 0;
	vec.size = 0;
	vec.data = NULL;

	return vec;
}

int main() {
       	vector vec = init_vector();

	return 0;
}
