/*
** EPITECH PROJECT, 2024
** /home/vj/code/lvstring/src/strcat
** File description:
** strcat and strncat
*/

#include <stddef.h>

char *lv_strcat(char *dest, const char *src)
{
    void *dest_start = dest;

    while (*dest != '\0')
        ++dest;
    do {
        *dest = *src;
        ++dest;
        ++src;
    } while (*(src - 1) != '\0');
    return dest_start;
}

char *lv_strncat(char *dest, const char *src, size_t n)
{
    void *dest_start = dest;

    while (*dest != '\0')
        ++dest;
    while (n > 0) {
        *dest = *src;
        ++dest;
        ++src;
        --n;
    }
    return dest_start;
}
