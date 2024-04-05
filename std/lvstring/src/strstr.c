/*
** EPITECH PROJECT, 2024
** /home/vj/code/lvstring/src/strstr
** File description:
** strstr
*/

#include <stddef.h>

char *strstr(const char *haystack, const char *needle)
{
    size_t j;

    for (size_t i = 0; haystack[i]; ++i) {
        for (j = 0; needle[j] && needle[j] == haystack[i + j]; ++j);
        if (!needle[j])
            return (char *)haystack + i;
    }
    return NULL;
}
