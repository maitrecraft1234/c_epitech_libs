/*
** EPITECH PROJECT, 2024
** src/strto/atoi
** File description:
** not very usefull but making this still
*/

#include <stddef.h>

int lv_atoi(char const *str)
{
    char sign = str[0] == '-' ? -1 : 1;
    int ret = 0;
    size_t len;

    str = (*str == '-' || *str == '+') ? str + 1 : str;
    for (; *str; ++str) {
        ret *= 10;
        ret += *str - '0';
    }
    return ret * sign;
}
