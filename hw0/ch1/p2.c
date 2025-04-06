#include <unistd.h>

// FD codes
// stdin  = 0
// stdout = 1
// stderr = 2

void write_triangle(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            write(1, "*", 1);
        }
        write(2, "\n", 1);
    }
}

int main() {
    write_triangle(5);
    return 0;
}