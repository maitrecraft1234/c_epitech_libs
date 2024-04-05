/*
** EPITECH PROJECT, 2024
** src/strdup
** File description:
** strdup, strndup
*/

#include "lvstrings.h"

char *lvs_strndup(const char *string, size_t n)
{
    char *dup = ALLOCATOR(sizeof(char) * (n + 1));

    lvs_memcpy(dup, string, n + 1);
    return dup;
}

char *lvs_strdup(const char *string)
{
    size_t n = lvs_strlen(string);
    char *dup = ALLOCATOR(sizeof(char) * (n + 1));

    lvs_memcpy(dup, string, n + 1);
    return dup;
}
