#include <stdio.h>
#include <stdlib.h>

int main() {
    char* data = "Hello 5 World";

    char word1[6];
    int num;
    char word2[6];

    int result = sscanf(data, "%5s %d %5s", word1, &num, word2);

    printf("Variables from scanning '%s':\n", data);
    printf("word 1: %s\n", word1);
    printf("number: %d\n", num);
    printf("word 2: %s\n", word2);
    return 0;
}
