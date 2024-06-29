/*
** EPITECH PROJECT, 2024
** /home/vj/coding/libs/lstr/include/lstr
** File description:
** stringis
*/

#pragma once

#include <stddef.h>
#include <stdbool.h>
#include "fn_types.h"
#include "version.h"

#define LSTR_VERSION VERSION

typedef struct lstr_ref_s {
    char *chars;
    size_t len;
} *lstr_ref_t;

typedef struct {
    struct lstr_ref_s ref;
    size_t cappacity;
} lstr_t;

/* new from array of known length
 * @param chars: array of characters
 * @param len: length of the array
 * @return lstr_t*: new string
 */
lstr_t *lstr_new_from_chars(char *chars, size_t len);
#define LSTR_NEW_FROM(literal) lstr_new_from_chars(literal, sizeof(literal)-1)

/* new from c string (null terminated)
 * @param cstr: c string
 * @return lstr_t*: new string
 */
lstr_t *lstr_new_from_cstr(char *cstr);

/* new with capacity
 * @param capacity: initial capacity
 * @return lstr_t*: new string
 */
lstr_t *lstr_new_with_capacity(size_t capacity);

/* new empty string
 * @return lstr_t*: new string
 */
lstr_t *lstr_new(void);

FN_DECL(lstr_new_from_file, (char *filepath), RESULT(lstr_t *, char *));

FN_DECL(lstr_get, (lstr_ref_t str, size_t index), OPTION(char));

void lstr_debug_print(lstr_t *str);
void lstr_print(lstr_t *str);


void lstr_push_char(lstr_t *str, char c);
FN_DECL(lstr_pop_char, (lstr_t *str, size_t len), OPTION(char));

void lstr_push_str(lstr_t *str, lstr_ref_t to_push);

void lstr_push_int(lstr_t *str, int nb);
void lstr_push_uint(lstr_t *str, unsigned int nb);

static inline size_t lstr_len(lstr_t *str)
{
    return str->ref.len;
}

static inline bool lstr_is_empty(lstr_t *str)
{
    return !str->ref.len;
}
