/*
** EPITECH PROJECT, 2024
** /home/vj/code/darrer/include/darrer
** File description:
** header for dynamic array library darrer
*/

#pragma once
#include <stddef.h>

// modify this depending on the size of arrays you will be using in you project
#define ARRAY_ALLOC_CEIL 1024

typedef struct {
    size_t current_len;
    size_t max_len;
} darrer_info_t;


//call these function to create and destroy dynamic arrays
void *da_create(size_t size);
void da_destroy(void *darray);

    #define DAC(ar, i) (ar = da_acces(ar, sizeof(*ar) * i))[i]
//used by macros
void *da_acces(void *array, size_t conv_i);

//function for simple utilities
void *da_push(void *array, void *data, size_t size);
void da_pop(void *array, size_t size);
