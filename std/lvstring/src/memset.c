/*
** EPITECH PROJECT, 2024
** /home/vj/code/lvstring/src/memcpy
** File description:
** simple memcpy
*/

#include <stddef.h>
#include <stdint.h>

void *lvs_memset(
        void *restrict dest,
        int value,
        size_t n)
{
    for (int i = n; i >= 0;) {
        i -= sizeof(uint8_t);
        *((uint8_t *)dest + i) = value;
    }
    return dest;
}
