/*
** EPITECH PROJECT, 2024
** /home/vj/code/lvstring/src/memcpy
** File description:
** simple memcpy
*/

#include <stddef.h>

//compiler will compile this as if it was the real memcpy
//somehow making this bs more optimal than the function bellow
//that does perfom 4x faster with no optimizations
//{
//    for (; n >= sizeof(uint64_t);) {
//        n -= sizeof(uint64_t);
//        *((uint64_t *)(((uint8_t *)dest + n))) =
//            *((uint64_t *)((uint8_t *)source + n));
//    }
//    for (; n >= sizeof(uint32_t);) {
//        n -= sizeof(uint32_t);
//        *((uint32_t *)(((uint8_t *)dest + n))) =
//            *((uint32_t *)((uint8_t *)source + n));
//    }
//    for (; n >= sizeof(uint16_t);) {
//        n -= sizeof(uint16_t);
//        *((uint16_t *)(((uint8_t *)dest + n))) =
//            *((uint16_t *)((uint8_t *)source + n));
//    }
//    for (int i = n; i >= 0;) {
//        i -= sizeof(uint8_t);
//        ((uint8_t *)dest)[i] = ((uint8_t *)source)[i];
//    }
//    return dest;
//}
void *lv_memcpy(
    void *restrict dest,
    const void *restrict source,
    size_t n)
{
    char *d = dest;
    char const *s = source;

    for (size_t i = 0; i < n; ++i)
        d[i] = s[i];
    return dest;
}

void *lv_memmove(
    void *dest,
    const void *source,
    size_t n)
{
    char *d = dest;
    char const *s = source;

    for (size_t i = 0; i < n; ++i)
        d[i] = s[i];
    return dest;
}
