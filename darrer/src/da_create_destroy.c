/*
** EPITECH PROJECT, 2024
** /home/vj/code/darrer/src/da_create_destroy
** File description:
** header file for dynamic array creating and destuction
*/

#include "darrer.h"
#include <malloc.h>

void *da_create(size_t size)
{
    darrer_info_t *new_dar = malloc(size + sizeof(darrer_info_t));
    darrer_info_t data = {0};

    data.max_len = size + (sizeof(darrer_info_t));
    data.current_len = sizeof(darrer_info_t);
    new_dar[0] = data;
    return new_dar + 1;
}

void da_destroy(void *darray)
{
    darrer_info_t *dar = (darrer_info_t *)darray - 1;

    free(dar);
}
