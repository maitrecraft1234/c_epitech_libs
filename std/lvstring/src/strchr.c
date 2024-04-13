/*
** EPITECH PROJECT, 2024
** src/strchr
** File description:
** strchr and strrchr
*/

#include "lv_string.h"

char *lv_strchr(const char *string, int search)
{
    while (*string) {
        if (*string == (char)search)
            return (void *)string;
        ++string;
    }
    return (void *)0;
}

char *lv_strrchr(const char *string, int search)
{
    size_t len = lv_strlen(string);

    while (len > 0 && string[len - 1]) {
        if (string[len - 1] == (char)search)
            return (void *)(string + len - 1);
        --len;
    }
    return (void *)0;
}
