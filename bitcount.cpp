#include "bitcount.h"

namespace {

// lookup table for the number of 1-bits in a nibble
const unsigned char bitcount_nibble[] = {0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};

// calculate the number of 1-bits in a byte based
// as a sum of upper/lower nibbles
unsigned char bitcount_char(unsigned char bitmap)
{
    return bitcount_nibble[bitmap&0x0f] + bitcount_nibble[bitmap>>4];
}

// count number of 1-bits in an array of bytes with size which is
// divisable by sizeof(unisgned int)
unsigned char bitcount_aligned(const char* bitmap, std::size_t len)
{
    unsigned char count = 0;
    const unsigned int* bitmap_chunk = reinterpret_cast<const unsigned int*>(bitmap);
    std::size_t remaining = len;
    while (remaining)
    {
        count += __builtin_popcount(*bitmap_chunk);
        ++bitmap_chunk;
        remaining -= sizeof(unsigned int);
    }
    return count;
}

// count number of 1-bits in an array of bytes
unsigned char bitcount_unaligned(const char* bitmap, std::size_t len)
{
    unsigned char count = 0;
    const char* bitmap_chunk = bitmap;
    std::size_t remaining = len;
    while (remaining)
    {
        count += bitcount_char(*bitmap_chunk);
        ++bitmap_chunk;
        remaining -= sizeof(unsigned char);
    }
    return count;
}

} // namespace

namespace bmapc
{

unsigned char bitcount(const char* bitmap, std::size_t len)
{
    if (len%sizeof(unsigned int) == 0)
    {
        // optimized for the case that the size of the array
        // is diviseable by sizeof(unisgned int)
        return bitcount_aligned(bitmap, len);
    }
    else
    {
        return bitcount_unaligned(bitmap, len);
    }
}

}

