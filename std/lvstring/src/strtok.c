/*
** EPITECH PROJECT, 2024
** /home/vj/code/lvstring/src/strtok
** File description:
** strtok strtok_r
*/

#include <stddef.h>
#include <stdio.h>

char *lvs_strtok_r(char *string, const char *delim, char **save)
{
    string = string ? string : *save;
    for (size_t i = 0; *string && delim[i];) {
        if (*string == delim[i]) {
            i = 0;
            ++string;
        } else
            ++i;
    }
    *save = string;
    for (size_t i = 0; **save && **save != delim[i];) {
        if (!delim[i]) {
            i = 0;
            ++*save;
        } else
            ++i;
    }
    *save = **save ? *save + 1 : NULL;
    if (*save)
        *(*save - 1) = '\0';
    return string;
}

char *lvs_strtok(char *string, const char *delim)
{
    static char *old;
    return lvs_strtok_r(string, delim, &old);
}
