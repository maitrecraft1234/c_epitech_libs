/*
** EPITECH PROJECT, 2024
** /home/vj/coding/libs/hotload/src/static/init
** File description:
** initalise the data here
*/

#include <stdlib.h>
#include "hotload.h"

void *init(int ac, char **av)
{
    data_t *data = calloc(sizeof(*data), 1);
    return data;
}
