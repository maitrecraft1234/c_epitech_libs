/*
** EPITECH PROJECT, 2024
** src/div/div
** File description:
** divs
*/

#include <stdlib.h>

div_t lv_div(int numer, int denom)
{
    div_t result;

    result.quot = numer / denom;
    result.rem = numer % denom;
    return result;
}

ldiv_t lv_ldiv(long numer, long denom)
{
    ldiv_t result;

    result.quot = numer / denom;
    result.rem = numer % denom;
    return result;
}

lldiv_t lv_lldiv(long long numer, long long denom)
{
    lldiv_t result;

    result.quot = numer / denom;
    result.rem = numer % denom;
    return result;
}
