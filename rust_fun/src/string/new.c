/*
** EPITECH PROJECT, 2024
** /home/vj/coding/libs/lstr/src/new
** File description:
** string and refs
*/

#include <stdlib.h>
#include <string.h>
#include "rust/fn_types.h"
#include "rust/libc.h"
#include "rust/strings.h"

lstr_t *lstr_new(void)
{
     return CALLOC(1, sizeof(*lstr_new()));
}

lstr_t *lstr_new_with_capacity(size_t capacity)
{
    lstr_t *str = MALLOC(sizeof(*str));

    str->ref.chars = MALLOC(capacity);
    str->cappacity = capacity;
    str->ref.len = 0;
    return str;
}

lstr_t *lstr_new_from_cstr(char *cstr)
{
    lstr_t *str = MALLOC(sizeof(*str));

    str->ref.len = strlen(cstr);
    str->ref.chars = MALLOC(str->ref.len);
    memcpy(str->ref.chars, cstr, str->ref.len);
    str->cappacity = str->ref.len;
    return str;
}

lstr_t *lstr_new_from_chars(char *chars, size_t len)
{
    lstr_t *str = MALLOC(sizeof(*str));

    str->ref.chars = MALLOC(len);
    memcpy(str->ref.chars, chars, len);
    str->ref.len = len;
    str->cappacity = len;
    return str;
}
