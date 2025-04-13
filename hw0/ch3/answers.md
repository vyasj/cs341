1. One way to find the length of `argv` is by using `sizeof()`, since it gives you the number of bytes that the pointer is referencing. Another way is to just use `argc`, since that is the number of arguments provided in the command line.
2. `argv[0]` represents the name of the executable.
3. Pointers to the environment variables are stored on the heap.
4. If the code is being run on a machine where pointers are 8 bytes, then `sizeof(ptr) = 8` and `sizeof(array) = 6`, because the pointer can only reference 8 bytes, whereas the array variable is referring to the entire character string, which has size 6 (5 characters plus the null character).
5. A stack manages the lifetime of automatic variables, and frees the appropriate addresses when the variables go out of scope.
