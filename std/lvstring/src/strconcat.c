/*
** EPITECH PROJECT, 2024
** /home/vj/code/std/lvstring/src/strconcat
** File description:
** strconcat
*/

#include "lvstrings.h"
#include <stddef.h>
#include <stdarg.h>

static size_t vaargs_len(va_list *ap)
{
    char const *str = va_arg(*ap, const char *);
    size_t out = lvs_strlen(str);

    for (; str; str = va_arg(*ap, const char *))
        out += lvs_strlen(str);
    return out;
}

static void vaargs_cat(char *dest, va_list *ap)
{
    char const *str = va_arg(*ap, const char *);

    for (; str; str = va_arg(*ap, const char *))
        (void)lvs_strcat(dest, str);
}

char *strconcat(const char *s, ...)
{
    va_list ap;
    va_list ap2;
    size_t out_len;
    char *dest;

    va_start(ap, s);
    va_copy(ap2, ap);
    out_len = vaargs_len(&ap) + lvs_strlen(s);
    dest = malloc(sizeof(*dest) * (out_len + 1));
    va_end(ap);
    vaargs_cat(dest, &ap2);
    va_end(ap2);
    return dest;
}
