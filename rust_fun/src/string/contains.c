/*
** EPITECH PROJECT, 2024
** /home/vj/coding/libs/lstr/src/contains
** File description:
** contain
*/

#include <string.h>
#include "rust/strings.h"

bool lstr_contains_char(lstr_ref_t str, char c)
{
    return memchr(str->chars, c, str->len) != NULL;
}

bool lstr_contains_lstr(lstr_ref_t haystack, lstr_ref_t needle)
{
    size_t j;

    for (size_t i = 0; i <= haystack->len; ++i) {
        for (j = 0; j <= needle->len &&
            needle->chars[j] == haystack->chars[i + j]; ++j);
        if (j > needle->len)
            return true;
    }
    return false;
}
