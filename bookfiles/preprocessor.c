#include <stdio.h>

#define min(a,b) a < b ? a : b

int test(int a) {
    if (a > 1) {
        printf("holy guacamole batman\n");
    }
    return a;
}

int main() {
    int x = 4;
    if(min(x++, 5)) printf("x=%d\n", x);

    int a = 1;
    printf("a=%d\n", test(a++));
    printf("----------\n");
    a = 1;
    printf("a=%d\n", test(++a));

    return 0;
}
