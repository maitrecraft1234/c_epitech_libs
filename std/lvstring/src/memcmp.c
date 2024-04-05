/*
** EPITECH PROJECT, 2024
** src/memcmp
** File description:
** memcmp
*/

#include <stddef.h>

int lvs_memcmp(const void *s1, const void *s2, size_t n)
{
    register const unsigned char *str1 = s1;
    register const unsigned char *str2 = s2;

    while (n > 0) {
        --n;
        if (*str1 != *str2)
            return *str1 - *str2;
        ++str1;
        ++str2;
    }
    return 0;
}
