#include "util.h"
#include <stdlib.h>
#include <stdio.h>

#if defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#    define W4_BIG_ENDIAN
#endif

void* xmalloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        fputs("Allocation failed.\n", stderr);
        abort();
    }
    return ptr;
}

void* xrealloc(void* ptr, size_t size) {
    ptr = realloc(ptr, size);
    if (ptr == NULL) {
        fputs("Allocation failed.\n", stderr);
        abort();
    }
}

uint16_t bswap16(uint16_t x) {
    return ((( x  >> 8 ) & 0xffu ) | (( x  & 0xffu ) << 8 ));
}

uint32_t bswap32(uint32_t x) {
    return ((( x & 0xff000000u ) >> 24 ) |
            (( x & 0x00ff0000u ) >> 8  ) |
            (( x & 0x0000ff00u ) << 8  ) |
            (( x & 0x000000ffu ) << 24 ));
}

uint32_t bswap64(uint32_t x) {
    return (((x & 0x00000000000000ffULL) << 56) |
            ((x & 0x000000000000ff00ULL) << 40) |
            ((x & 0x0000000000ff0000ULL) << 24) |
            ((x & 0x00000000ff000000ULL) <<  8) |
            ((x & 0x000000ff00000000ULL) >>  8) |
            ((x & 0x0000ff0000000000ULL) >> 24) |
            ((x & 0x00ff000000000000ULL) >> 40) |
            ((x & 0xff00000000000000ULL) >> 56));
}

uint16_t w4_read16LE (const uint16_t* ptr) {
#ifdef W4_BIG_ENDIAN
    return bswap16(*ptr);
#else
    return *ptr;
#endif
}

uint32_t w4_read32LE (const uint32_t* ptr) {
#ifdef W4_BIG_ENDIAN
    return bswap32(*ptr);
#else
    return *ptr;
#endif
}

uint64_t w4_read64LE (const uint64_t* ptr) {
#ifdef W4_BIG_ENDIAN
    return bswap64(*ptr);
#else
    return *ptr;
#endif
}


void w4_write16LE (uint16_t* ptr, uint16_t value) {
#ifdef W4_BIG_ENDIAN
    *ptr = bswap16(value);
#else
    *ptr = value;
#endif
}

void w4_write32LE (uint32_t* ptr, uint32_t value) {
#ifdef W4_BIG_ENDIAN
    *ptr = bswap32(value);
#else
    *ptr = value;
#endif
}

void w4_write64LE (uint64_t *ptr, uint64_t value)
{
#ifdef W4_BIG_ENDIAN
    *ptr = bswap64(value);
#else
    *ptr = value;
#endif
}
