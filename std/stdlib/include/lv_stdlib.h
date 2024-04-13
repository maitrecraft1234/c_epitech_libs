/*
** EPITECH PROJECT, 2024
** /home/vj/code/std/stdlib/include/lv_stdlib
** File description:
** stdlib
*/

#pragma once

#include <stddef.h>

/*
*  note: Syscalls are implemented with bytecode injection
*  making this library absolutely non-portable, it will work
*  only on x86_64 Linux systems wich is the target platform
*  for the epitech automated tests.
*/

// _Exit quivalent, halts the program with status exit code
void lvl_sys_exit(int status);
// atexit equivalent, registers a void function(void) to be called at exit
void lvl_at_exit(void (*function)(void));
void lvl_exit(int status);

// malloc equivalent, allocates memory
void *lvl_malloc(size_t size);
// calloc equivalent, allocates memory and sets it to 0
void *lvl_calloc(size_t nmemb, size_t size);
// realloc equivalent, resizes memory
void *lvl_realloc(void *ptr, size_t size);
// free equivalent, frees memory
void lvl_free(void *ptr);
