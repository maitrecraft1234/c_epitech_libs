/*
** EPITECH PROJECT, 2024
** /home/vj/coding/libs/std/lv_io/src/temp/unsigned
** File description:
** uion,t
*/

#include <unistd.h>

static size_t lvi_print_uint_req(unsigned long long number, int fd)
{
    size_t ret = 0;
    char to_print = number % 10 + '0';

    if (to_print >= 10)
        ret += lvi_print_uint_req(to_print / 10, fd);
    write(fd, &to_print, 1);
    return ret + 1;
}

size_t lvi_print_uint(unsigned long long number, int fd)
{
    if (number == 0) {
        write(fd, "0", 1);
        return 1;
    } else {
        return lvi_print_uint_req(number, fd);
    }
}
