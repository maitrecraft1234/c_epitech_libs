/*
** EPITECH PROJECT, 2024
** /home/vj/coding/libs/rust_fun/src/libc_wrappers/open
** File description:
** open wrapper with result
*/

#include <fcntl.h>
#include <unistd.h>
#include "rust/fn_types.h"
#include "rust/libc.h"

PUB_FN(open_wrap, (char *path, int flags), RESULT(int, char *),
        LET file_desc = open(path, flags);

        if (file_desc == -1)
        return ERR("open failed");
        OK(file_desc);
  )

PUB_FN(close_wrap, (int fd), RESULT(int, char *),
        LET ret = close(fd);

        if (ret == -1)
        return ERR("close failed");
        OK(ret);
  )
