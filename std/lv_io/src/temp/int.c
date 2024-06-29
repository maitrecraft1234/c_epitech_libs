/*
** EPITECH PROJECT, 2024
** /home/vj/coding/libs/std/lv_io/src/lvi_print/int
** File description:
** simple int printer
*/

#include <unistd.h>
#include "temp.h"

size_t lvi_print_int(long long to_print, int fd)
{
    size_t ret = 0;

    if (to_print < 0) {
        write(fd, "-", 1);
        to_print = -to_print;
        ++ret;
    }
    return lvi_print_uint(to_print, fd) + ret;
}
