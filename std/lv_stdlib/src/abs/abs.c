/*
** EPITECH PROJECT, 2024
** /home/vj/code/libs/std/lv_stdlib/src/abs/abs
** File description:
** abs
*/

int lv_abs(int nb)
{
    return nb < 0 ? -nb : nb;
}

long lv_labs(long nb)
{
    return nb < 0 ? -nb : nb;
}

long long lv_llabs(long long nb)
{
    return nb < 0 ? -nb : nb;
}
