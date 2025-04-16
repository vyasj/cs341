1. The `getchar()` and `gets()` functions can be used for getting characters from `stdin`, and the `putchar()` and `puts()` functions can be used for printing characters out.
2. `gets()` does not stop reading in characters once they go over the buffer limit, since a buffer of a predetermined size has to be allocated. This can result in corrupted data.
4. You have to define `_GNU_SOURCE`, as that tells the compiler that you will be using functions which were omitted from the POSIX standard.
