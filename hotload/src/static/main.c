/*
** EPITECH PROJECT, 2024
** /home/vj/coding/libs/hotload/src/main
** File description:
** main statis file
*/

#include <unistd.h>
#include <stdio.h>
#include <dlfcn.h>
#include <stddef.h>
#include <stdlib.h>
#include "hotload.h"

static const char *const LIBLOOP = "./libloop.so";

int main(int ac, char **av)
{
    void *data = init(ac, av);
    void *loop_mod;
    int (*loop_fn)(void *) = NULL;

    for (data = init(ac, av);;) {
        while (system("make libloop.so") != 0)
            sleep(1);
        loop_mod = dlopen(LIBLOOP, RTLD_NOW);
        if (!loop_mod)
            continue;
        loop_fn = dlsym(loop_mod, "loop");
        if (loop_fn && !loop_fn(data))
            break;
        dlclose(loop_mod);
    }
    return finit(data);
}
