/*
** EPITECH PROJECT, 2024
** /home/vj/code/std/lvstring/src/strconcat
** File description:
** strconcat
*/

#include "lv_string.h"
#include <stddef.h>
#include <stdarg.h>

static size_t lvi_vaargs_len(va_list *ap)
{
    char const *str = va_arg(*ap, const char *);
    size_t out = lv_strlen(str);

    for (; str; str = va_arg(*ap, const char *))
        out += lv_strlen(str);
    return out;
}

static void lvi_vaargs_cat(char *dest, va_list *ap)
{
    char const *str = va_arg(*ap, const char *);

    for (; str; str = va_arg(*ap, const char *))
        (void)lv_strcat(dest, str);
}

char *lv_strconcat(const char *s, ...)
{
    va_list ap;
    va_list ap2;
    size_t out_len;
    char *dest;

    va_start(ap, s);
    va_copy(ap2, ap);
    out_len = lvi_vaargs_len(&ap) + lv_strlen(s);
    dest = malloc(sizeof(*dest) * (out_len + 1));
    va_end(ap);
    lvi_vaargs_cat(dest, &ap2);
    va_end(ap2);
    return dest;
}
