#define _GNU_STANDARD
#include <stdio.h>
#include <stdlib.h>

int main() {
    char buf[32];
    char* buf2 = NULL;
    size_t cap = 0;

    printf("Enter the filename to scan:\n");
    int scanf_result = scanf("%31s", buf);

    ssize_t result = getline(&buf2, &cap, fopen(buf, "r"));

    printf("%zd : %s\n", result, buf2);
    return 0;
}
