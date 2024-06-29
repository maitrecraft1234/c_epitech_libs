/*
** EPITECH PROJECT, 2024
** /home/vj/coding/libs/rust_fun/src/libc_wrappers/stat
** File description:
** stat fstat
*/

#include <sys/stat.h>
#include "rust/fn_types.h"
#include "rust/libc.h"

PUB_FN(stat_wrap, (char *path, struct stat *buf), RESULT(int, char *),
    LET ret = stat(path, buf);

    if (ret == -1)
        return ERR("stat failed");
    OK(ret);
)

PUB_FN(fstat_wrap, (int fd, struct stat *buf), RESULT(int, char *),
    LET ret = fstat(fd, buf);

    if (ret == -1)
        return ERR("fstat failed");
    OK(ret);
)
