1. You can put it on the heap by calling `malloc()`.
2. The memory on the stack gets automatically cleaned, since the stack is primarily used for function calls, and when the function returns, all of the memory addresses of the variables defined in that function are ready to get overwritten. In the heap, the memory address remains fully usable until the end of the program, but you need a pointer to reference it.
3. There is the stack and heap which is where memory gets stored/allocated.
4. In a good C program, for every `malloc`, there is a `free`.
5. `malloc` can fail if the operation is trying to allocate more memory than is available.
6. `time()` gives you a `time_t` variable that is the number of seconds since January 1st, 00:00:00 1970. `ctime()` returns a `char*` for the output of `time()`.
7. The snippet tries to free the same pointer twice, once the data has been freed then the variable no longer points to a valid address in memory.
8. The snippet tries to print the contents of the pointer after it has been freed, but there will be nothing in the pointer data to print.
9. In question 7, there only needs to be one `free` for every `malloc`, so the first `free` should be a `malloc`, or if therewas already a `malloc` earlier, there only needs to be one `free`. You could also just set `ptr = NULL` after the first `free`, as that would render the second `free` harmless. For question 8, the `free` should be moved after the `printf`. You could again also set `ptr = NULL`, which would just print out `(null)`.
