#include <unistd.h>

int main() {
    write(1, "Hi\n", 3);
    return 0;
}