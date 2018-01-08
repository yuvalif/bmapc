#pragma once 
#include <cstddef>

namespace bmapc
{
    // return number of 1-bits in a bitmap of given length
    unsigned char bitcount(const char* bitmap, std::size_t len);
}

