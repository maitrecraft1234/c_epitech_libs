/*
** EPITECH PROJECT, 2024
** /home/vj/coding/libs/std/lv_io/src/temp/temp
** File description:
** this is meant to be usable for now
** but I plan on making file streams before making
** more complete functions
*/

#include <unistd.h>

size_t lvi_print_int(long long to_print, int fd);
size_t lvi_print_string(char *to_print, int fd);
size_t lvi_print_uint(unsigned long long number, int fd);
size_t lvi_print_float(double to_print, int fd);
