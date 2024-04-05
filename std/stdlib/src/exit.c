/*
** EPITECH PROJECT, 2024
** /home/vj/code/std/stdlib/src/exit
** File description:
** exit function
*/

#include "exit.h"

static int lvl_builtin_exit_main(int status, char **unused)
{
    (void)unused;
    return status;
}

void lvl_sys_exit(int status)
{
#if defined (__GNUC__)
    __libc_start_main(lvl_builtin_exit_main, status, 0, 0, 0, 0, 0);
    __builtin_unreachable();
#endif
    while(1);
}
