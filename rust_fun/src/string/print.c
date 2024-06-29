/*
** EPITECH PROJECT, 2024
** /home/vj/coding/libs/lstr/src/print
** File description:
** print and debug print
*/

#include <stdio.h>
#include "rust/strings.h"

void lstr_print(lstr_t *str)
{
    fwrite(str->ref.chars, 1, str->ref.len, stdout);
}

void lstr_debug_print(lstr_t *str)
{
    printf("lstr_t{ref.chars: %p, ref.len: %lu, cappacity: %lu}\n",
        str->ref.chars, str->ref.len, str->cappacity);
}
