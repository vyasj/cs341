#include <stdio.h>
#include <stdlib.h>

int main() {
    int c;
    while((c=getchar()) != EOF) {
        if(c>=32) c = c ^ 0b1;
        putchar(c);
    }
    return EXIT_SUCCESS;
}
