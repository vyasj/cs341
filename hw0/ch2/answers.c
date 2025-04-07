#include <stdio.h>
#include <string.h>

int main() {
    printf("sizeof(char) is %lu \n", sizeof(char));

    printf("sizeof(int) is %lu \n", sizeof(int));
    printf("sizeof(double) is %lu \n", sizeof(double));
    printf("sizeof(float) is %lu \n", sizeof(float));
    printf("sizeof(long) is %lu \n", sizeof(long));
    printf("sizeof(long long) is %lu \n", sizeof(long long));
    
    ssize_t str_size = sizeof("Hello\0World");
    ssize_t str_len = strlen("Hello\0World");

    printf("sizeof(Hello\\0World) is %d \n", str_size);
    printf("strlen(Hello\\0World) is %d \n", str_len);

    return 0;
}