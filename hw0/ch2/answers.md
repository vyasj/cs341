1. There are 8 bits in a byte.
2. There can be at least 1 byte in a `char`, it depends on your system's architecture. On my machine, it is 1 byte.
3. On my machine, an `int` is 4 bytes, a `double` is 8 bytes, a `float` is 4 bytes, a `long` is 8 bytes, and a `long long` is 8 bytes.
4. The address of `data+2` would be `0x7fbd9d50`
5. In C, the equivalent to `data[3]` is `*(data+3)`.
6. The code segaults because the string pointer gets placed in read-only memory, and trying to edit that memory after the fact is not allowed, causing the program to crash.
7. The value of `str_size` here would be 12, because the two words are 5 characters each, the null character in the middle is the 11th character, and the null character that gets appended at the end is the 12th character.
8. The variable `str_len` here would be 5, because the escape code `'\0'` is the null character and truncates everything after it in the string, leaving only the word `"Hello"`.
9. In order to have `sizeof(X) = 3`, X could be something like the string `"hi"`.
10. In order to have `sizeof(Y) = 4` or `sizeof(Y) = 8` depending on the architecture, Y could be an `int`.