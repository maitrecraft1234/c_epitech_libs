/*
** EPITECH PROJECT, 2024
** /home/vj/coding/libs/lstr/src/push_pop
** File description:
** push and pop character and string
*/

#include <string.h>
#include "rust/fn_types.h"
#include "rust/libc.h"
#include "rust/strings.h"

void lstr_push_char(lstr_t *str, char c)
{
    if (str->ref.len == str->cappacity) {
        str->cappacity = str->cappacity == 0 ? 8 : str->cappacity * 2;
        str->ref.chars = REALLOC(str->ref.chars, str->cappacity);
    }
    str->ref.chars[str->ref.len] = c;
    ++str->ref.len;
}

PUB_FN(lstr_pop_char, (lstr_t *str, size_t len), OPTION(char),
    if (str->ref.len == 0)
        return NONE;
    --str->ref.len;
    SOME(str->ref.chars[str->ref.len + 1]);
      )

void lstr_push_str(lstr_t *str, lstr_ref_t to_push)
{
    if (str->ref.len + to_push->len > str->cappacity) {
        str->cappacity += to_push->len;
        str->ref.chars = REALLOC(str->ref.chars, str->cappacity);
    }
    memcpy(str->ref.chars + str->ref.len, to_push->chars, to_push->len);
    str->ref.len += to_push->len;
}
