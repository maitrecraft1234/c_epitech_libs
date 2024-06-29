/*
** EPITECH PROJECT, 2024
** /home/vj/coding/libs/rust_fun/rust
** File description:
** rust helper functions
*/

#include <stdio.h>
#include <stdlib.h>

__attribute__((noreturn))
void panic(char *msg, char *file, size_t line)
{
    printf("Panic: %s at %s:%lu\n", msg, file, line);
    exit(84);
}
