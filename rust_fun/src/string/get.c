/*
** EPITECH PROJECT, 2024
** /home/vj/coding/libs/lstr/src/get
** File description:
** get the thing
*/

#include <stdlib.h>
#include "rust/fn_types.h"
#include "rust/strings.h"


PUB_FN(lstr_get, (lstr_ref_t str, size_t index), OPTION(char),
        if (index >= str->len)
            return NONE;
        SOME(str->chars[index]);
      )
