/*
** EPITECH PROJECT, 2024
** /home/vj/code/darrer/src/da_modify
** File description:
** functions for simple modifications of the da
** push to add and pop to remove ()
*/

#include "darrer.h"
#include <malloc.h>

static void da_int_memcpy(unsigned char *dest, unsigned char *src, size_t size)
{
    for (; size; --size) {
        *dest = *src;
        ++src;
        ++dest;
    }
}

static void *da_int_realloc(void *info_ar, size_t new_size)
{
    darrer_info_t *info = info_ar;
    size_t na = (new_size - (new_size % ARRAY_ALLOC_CEIL)) + ARRAY_ALLOC_CEIL;
    darrer_info_t *new;

    new = malloc(na);
    da_int_memcpy((void *)new, (void *)info, info->current_len);
    free(info_ar);
    new->max_len = na;
    return new;
}

void *da_push(void *array, void *data, size_t size)
{
    darrer_info_t *info = (darrer_info_t *)array - 1;

    if (info->current_len + size >= info->max_len) {
        info = da_int_realloc(info, info->current_len + size);
        array = info + 1;
    }
    da_int_memcpy((unsigned char *)info + info->current_len, data, size);
    info->current_len += size;
    return array;
}

void *da_acces(void *array, size_t conv_i)
{
    darrer_info_t *info = (darrer_info_t *)array - 1;

    conv_i += sizeof(darrer_info_t);
    if (conv_i >= info->max_len) {
        info->current_len = conv_i;
        info = da_int_realloc(info, conv_i);
        array = info + 1;
    }
    if (conv_i > info->current_len)
        info->current_len = conv_i;
    return array;
}

void da_pop(void *array, size_t size)
{
    darrer_info_t *info = (darrer_info_t *)array - 1;

    info->current_len -= size;
}
