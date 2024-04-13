/*
** EPITECH PROJECT, 2024
** src/strdup
** File description:
** strdup, strndup
*/

#include "lv_string.h"

char *lv_strndup(const char *string, size_t n)
{
    char *dup = ALLOCATOR(sizeof(char) * (n + 1));

    lv_memcpy(dup, string, n + 1);
    return dup;
}

char *lv_strdup(const char *string)
{
    size_t n = lv_strlen(string);
    char *dup = ALLOCATOR(sizeof(char) * (n + 1));

    lv_memcpy(dup, string, n + 1);
    return dup;
}
