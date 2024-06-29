/*
** EPITECH PROJECT, 2024
** /home/vj/coding/libs/std/lv_io/src/temp/float
** File description:
** C-x C-c
*/

#include <unistd.h>
#include "temp.h"

size_t lvi_print_float(double to_print, int fd)
{
    int ret = 0;
    long long int_part = (long long)to_print;
    double float_part = to_print - int_part;

    ret += lvi_print_int(int_part, fd);
    write(fd, ".", 1);
    ret += 1;
    if (float_part < 0)
        float_part = -float_part;
    for (int i = 0; i < 6; i++) {
        float_part *= 10;
        int_part = (long long)float_part;
        ret += lvi_print_int(int_part, fd);
        float_part -= to_print;
    }
    return ret;
}
