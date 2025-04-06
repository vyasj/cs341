#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    mode_t mode = S_IRUSR | S_IWUSR;
    int fd = open("hello_world.txt", O_CREAT | O_TRUNC | O_RDWR, mode);
    printf("Hello, World!\n");
    write(fd, "Hello, World!\n", 14);
    return 0;
}