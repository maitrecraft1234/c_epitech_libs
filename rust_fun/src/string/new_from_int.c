/*
** EPITECH PROJECT, 2024
** /home/vj/coding/libs/lstr/src/new_from_int
** File description:
** creating a str from int / unsigned int
*/

#include <stdlib.h>
#include <string.h>
#include "rust/strings.h"

lstr_t *lstr_new_from_uint(unsigned int nb)
{
    lstr_t *lstr = lstr_new();

    lstr_push_uint(lstr, nb);
    return lstr;
}

lstr_t *lstr_new_from_int(int nb)
{
    lstr_t *lstr = lstr_new();

    lstr_push_int(lstr, nb);
    return lstr;
}
