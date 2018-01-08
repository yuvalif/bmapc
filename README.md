# bmapc
Bitmap Count provide a function that calculates the number of 1-bits in a bitmap. Function is optimized for the case where the array size is divisable by size of int, then it uses the compiler builtin function: `__builtin_popcount` (available in gcc and clang).
If a different compiler need to be used, this project: https://github.com/Noctune/bitcount provide a more general implementation of the popcount function.

Use the folowing command to build the test: `g++ -Wall -o test_bitcount test_bitcount.cpp bitcount.cpp`
