/*
** EPITECH PROJECT, 2024
** /home/vj/coding/libs/lstr/src/new_from_file
** File description:
** creating a str from a file
*/

#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include "rust/libc.h"
#include "rust/strings.h"

PUB_FN(lstr_new_from_file, (char *filepath), RESULT(lstr_t *, char *),
    LET fd = TRY(open_wrap(filepath, O_RDONLY));
    struct stat st;

    TRY(fstat_wrap(fd, &st));
    lstr_t *lstr = lstr_new_with_capacity(st.st_size);
    read(fd, lstr->ref.chars, st.st_size);
    lstr->ref.len = st.st_size;
    TRY(close_wrap(fd));
    OK(lstr);
)
