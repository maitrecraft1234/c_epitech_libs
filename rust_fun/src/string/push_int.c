/*
** EPITECH PROJECT, 2024
** /home/vj/coding/libs/lstr/src/push_int
** File description:
** push integer types
*/

#include "rust/libc.h"
#include "rust/strings.h"

void lstr_push_uint(lstr_t *str, unsigned int nb)
{
    if (str->cappacity == 0) {
        str->cappacity = 10;
        str->ref.chars = MALLOC(str->cappacity);
    }
    do {
        lstr_push_char(str, nb % 10 + '0');
        nb /= 10;
    } while (nb != 0);
}

void lstr_push_int(lstr_t *str, int nb)
{
    if (nb < 0) {
        if (str->cappacity == 0) {
            str->cappacity = 11;
            str->ref.chars = MALLOC(str->cappacity);
        }
        lstr_push_char(str, '-');
        lstr_push_uint(str, -nb);
    } else
        lstr_push_uint(str, nb);
}
