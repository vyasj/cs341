#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* currentTime() {
    char* result = malloc(128);
    if (!result) return result;
    time_t sec = time(NULL);

    strcpy(result, ctime(&sec));
    return result;
}

int main() {
    char* ptr = currentTime();
    printf("%s\n", ptr);
    free(ptr);
    ptr = NULL;
    free(ptr);
    printf("freed ptr: %s\n", ptr);
    return 0;
}
