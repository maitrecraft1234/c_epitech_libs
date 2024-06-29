/*
** EPITECH PROJECT, 2024
** /home/vj/coding/libs/lstr/src/concat
** File description:
** Concatenate string
*/

#include "rust/fn_types.h"
#include "rust/strings.h"

lstr_t *lstr_concat(lstr_ref_t str1, lstr_ref_t str2)
{
    LET new_str = lstr_new_with_capacity(str1->len + str2->len);

    lstr_push_str(new_str, str1);
    lstr_push_str(new_str, str2);
    return new_str;
}
