/*
** EPITECH PROJECT, 2024
** src/strto/atoll
** File description:
** not very usefull but making this still
*/

long long lv_atoll(char const *str)
{
    char sign = str[0] == '-' ? -1 : 1;
    long long ret = 0;

    str = (*str == '-' || *str == '+') ? str + 1 : str;
    for (; *str; ++str) {
        ret *= 10;
        ret += *str - '0';
    }
    return ret * sign;
}
