/*
** EPITECH PROJECT, 2024
** /home/vj/coding/libs/rust_fun/src/libc_wrappers/alloc
** File description:
** alloc
*/

#include <stdlib.h>
#include "rust/libc.h"
#include "rust/fn_types.h"

PUB_FN(malloc_wrap, (size_t size), RESULT(void *, char *),
    LET ptr = malloc(size);

    if (!ptr)
        return ERR("malloc failed");
    OK(ptr);
)

PUB_FN(calloc_wrap, (size_t nmemb, size_t size), RESULT(void *, char *),
    LET ptr = calloc(nmemb, size);

    if (!ptr)
        return ERR("calloc failed");
    OK(ptr);
)

PUB_FN(realloc_wrap, (void *ptr, size_t size), RESULT(void *, char *),
    LET new_ptr = realloc(ptr, size);

    if (!new_ptr)
        return ERR("realloc failed");
    OK(new_ptr);
)
