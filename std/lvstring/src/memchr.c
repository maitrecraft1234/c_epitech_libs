/*
** EPITECH PROJECT, 2024
** /home/vj/code/lvstring/src/memchr
** File description:
** memchr
*/

#include <stddef.h>

void *memchr(const void *buffer, int search, size_t n)
{
    const char *buf = buffer;
    const unsigned char s = search;

    for (size_t i = 0; i < n; ++i) {
        if (*buf == s)
            return (void *)buf;
        ++buf;
    }
    return NULL;
}
