/*
** EPITECH PROJECT, 2024
** /home/vj/code/libs/std/stdlib/src/allocation/calloc
** File description:
** calloc simple implementation gcc will optimize
*/

#include "lv_stdlib.h"

void *lv_calloc(size_t nmemb, size_t size)
{
    void *alloc = lv_malloc(nmemb * size);

    if (alloc == NULL)
        return NULL;
    for (size_t i = 0; i < nmemb * size; ++i)
        ((unsigned char *)alloc)[i] = 0;
    return alloc;
}
