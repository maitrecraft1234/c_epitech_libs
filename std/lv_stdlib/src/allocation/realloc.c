/*
** EPITECH PROJECT, 2024
** /home/vj/code/libs/std/stdlib/src/allocation/realloc
** File description:
** realloc
*/

//temporary realloc not optimized yet, malloc and free need to be implemented
//first

#include "lv_stdlib.h"

void *lv_realloc(void *ptr, size_t size)
{
    void *new_ptr = lv_malloc(size);

    if (new_ptr)
        for (size_t i = 0; i < size; ++i)
            ((unsigned char *)new_ptr)[i] = ((unsigned char *)ptr)[i];
    lv_free(ptr);
    return new_ptr;
}
