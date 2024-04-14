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
    char *last_oc = 0;

    while (*string) {
        if (*string == (char)search)
            last_oc = (void *)string;
        ++string;
    }
    return last_oc;
}
