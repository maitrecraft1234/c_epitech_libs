/*
** EPITECH PROJECT, 2024
** /home/vj/code/lvstring/src/strlen
** File description:
** strlenthingy
*/

#include <stddef.h>

size_t lvs_strlen(char *string)
{
    size_t len;

    for (len = 0; string[len]; ++len);
    return len;
}
