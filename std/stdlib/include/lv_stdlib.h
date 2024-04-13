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
void lv_sys_exit(int status);
// atexit equivalent, registers a void function(void) to be called at exit
void lv_atexit(void (*function)(void));
void lv_exit(int status);

// malloc equivalent, allocates memory
void *lv_malloc(size_t size);
// calloc equivalent, allocates memory and sets it to 0
void *lv_calloc(size_t nmemb, size_t size);
// realloc equivalent, resizes memory
void *lv_realloc(void *ptr, size_t size);
// free equivalent, frees memory
void lv_free(void *ptr);
