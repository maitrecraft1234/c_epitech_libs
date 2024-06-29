/*
** EPITECH PROJECT, 2024
** /home/vj/coding/libs/rust_fun/include/rust/libc
** File description:
** libcwrappers
*/

#pragma once

#include "version.h"
#include <stddef.h>
#include <sys/stat.h>
#include "fn_types.h"

#define LIBC_VERSION VERSION

FN_DECL(open_wrap, (char *path, int flags), RESULT(int, char *));
FN_DECL(close_wrap, (int fd), RESULT(int, char *));


FN_DECL(stat_wrap, (char *path, struct stat *buf), RESULT(int, char *));
FN_DECL(fstat_wrap, (int fd, struct stat *buf), RESULT(int, char *));

FN_DECL(malloc_wrap, (size_t size), RESULT(void *, char *));
#define MALLOC(size) EXPECT(malloc_wrap(size), "malloc failed")

FN_DECL(calloc_wrap, (size_t nmemb, size_t size), RESULT(void *, char *));
#define CALLOC(nmemb, size) EXPECT(calloc_wrap(nmemb, size), "calloc failed")

FN_DECL(realloc_wrap, (void *ptr, size_t size), RESULT(void *, char *));
#define REALLOC(ptr, size) EXPECT(realloc_wrap(ptr, size), "realloc failed")
