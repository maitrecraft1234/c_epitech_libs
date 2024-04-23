/*
** EPITECH PROJECT, 2024
** src/strto/atoll
** File description:
** not very usefull but making this still
*/

#include <stddef.h>

double lv_atof(char const *str)
{
    char sign = str[0] == '-' ? -1 : 1;
    double ret = 0;
    size_t decimals = 10;

    str = (*str == '-' || *str == '+') ? str + 1 : str;
    for (; *str && *str != '.'; ++str) {
        ret *= 10;
        ret += *str - '0';
    }
    for (str = *str == '.' ? str + 1 : str; *str; ++str) {
        ret += (*str - '0') / (double)decimals;
        decimals *= 10;
    }
    return ret * sign;
}
