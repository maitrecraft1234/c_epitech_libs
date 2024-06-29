/*
** EPITECH PROJECT, 2024
** /home/vj/coding/libs/std/lv_io/src/temp/string
** File description:
** fireplace 4k
*/

#include <unistd.h>

size_t lvi_print_string(char *to_print, int fd)
{
    size_t ret = 0;

    for (; to_print[ret]; ret++);
    write(fd, to_print, ret);
    return ret;
}
