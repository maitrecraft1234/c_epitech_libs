/*
** EPITECH PROJECT, 2024
** /home/vj/coding/libs/std/lv_io/src/temp/lve_dprint
** File description:
** light printf
*/

#include <unistd.h>
#include <stdarg.h>
#include "temp.h"

static size_t lvi_switch(char c, va_list args, int fd)
{
    int tmp;

    if (c == 'd')
        return lvi_print_int(va_arg(args, int), fd);
    if (c == 's')
        return lvi_print_string(va_arg(args, char *), fd);
    if (c == 'u')
        return lvi_print_uint(va_arg(args, unsigned int), fd);
    if (c == 'c') {
        tmp = va_arg(args, int);
        return write(fd, &tmp, 1);
    }
    if (c == '%')
        return write(fd, "%", 1);
    if (c == 'f')
        return lvi_print_float(va_arg(args, double), fd);
    return 0;
}

size_t lve_printl(int fd, char *format, ...)
{
    va_list args;
    size_t ret = 0;

    va_start(args, format);
    for (size_t i = 0; format[i]; ++i) {
        if (format[i] == '%') {
            ++i;
            ret += lvi_switch(format[i], args, fd);
        } else {
            write(fd, format + i, 1);
            ret++;
        }
    }
    va_end(args);
    return ret;
}
