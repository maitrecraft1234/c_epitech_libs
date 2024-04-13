/*
** EPITECH PROJECT, 2024
** /home/vj/code/lvstring/src/strspn
** File description:
** strspn
*/

#include <stddef.h>
#include <stdbool.h>

size_t lv_strspn(const char *string, const char *accept)
{
    size_t len;
    bool contine = true;

    for (len = 0; contine; ++len) {
        contine = false;
        for (size_t i = 0; !contine && accept[i]; ++i)
            contine = accept[i] == string[len];
    }
    return len;
}

size_t lv_strcspn(const char *string, const char *reject)
{
    size_t len;
    bool contine = true;

    for (len = 0; contine; ++len) {
        contine = true;
        for (size_t i = 0; contine && reject[i]; ++i)
            contine = reject[i] != string[len];
    }
    return len;
}
