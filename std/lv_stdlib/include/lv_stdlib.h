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

// returns the absolute value of given integer
int lv_abs(int nb);
// returns the absolute value of given long integer
long lv_labs(long nb);
// returns the absolute value of given long long integer
long long lv_llabs(long long nb);

// including stdlib for div_t, ldiv_t, lldiv_t
#include <stdlib.h>
// doas what div does
div_t lv_div(int numer, int denom);
ldiv_t lv_ldiv(long numer, long denom);
lldiv_t lv_lldiv(long long numer, long long denom);

//yet to be implemented
void lv_qsort(void *array, size_t element_count, size_t element_size,
    int (*cmp)(const void *, const void *));

// rand equivalent, returns a pseudo-random number
int lv_rand(void);
// sets the seed for the pseudo-random number generator used by rand
void lv_srand(unsigned int seed);

//array to int lots of ub no error handling is meant to happen
int lv_atoi(char const *str);
//array to double precision floating point still no error handling
double lv_atof(char const *str);
//array to long no error handling
long lv_atol(char const *str);
//array to long long no error handling
long long lv_atoll(char const *str);
