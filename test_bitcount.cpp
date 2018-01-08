#include "bitcount.h"
#include <iostream>

int main()
{
    char bitmap[1024] = {0};
    bitmap[0] = 1;
    bitmap[3] = 1;
    bitmap[33] = 1;
    bitmap[333] = 1;
    bitmap[999] = 1;
    bitmap[1023] = 1;

    std::cout << "expect 6, get " << 
        static_cast<unsigned int>(bmapc::bitcount(bitmap, 1024)) << std::endl;

    std::cout << "expect 4, get " << 
        static_cast<unsigned int>(bmapc::bitcount(bitmap, 997)) << std::endl;

    return 0;
}

