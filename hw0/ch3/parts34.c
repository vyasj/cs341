#include <stdio.h>

extern char** environ;

int main() {
    char** ptr = environ;
    printf("sizeof(ptr) = %lu\n", sizeof(ptr));
    while(*ptr) {
        printf("var: %s, addr: %p\n", *ptr, &ptr);
        ptr++;
    }

    char* ptr2 = "Hello";
    char array[] = "Hello";
    printf("sizeof(ptr)=%lu, sizeof(array)=%lu\n", sizeof(ptr2), sizeof(array));
    return 0;
}
