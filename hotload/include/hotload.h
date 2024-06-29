/*
** EPITECH PROJECT, 2024
** /home/vj/coding/libs/hotload/include/data
** File description:
** data header
*/

#pragma once

/// example data structure save you could make an allocator for
typedef struct data_s {
    unsigned char mem[1024];
} data_t;

void *init(int ac, char **av);
int finit(void *data);
int loop(void *data);
