/*
** EPITECH PROJECT, 2024
** /home/vj/coding/libs/hotload/src/static/finit
** File description:
** example of finit
*/

#include <stdlib.h>

int finit(void *data)
{
    free(data);
    return 0;
}
