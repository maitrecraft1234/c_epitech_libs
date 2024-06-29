/*
** EPITECH PROJECT, 2024
** src/dynamic/loop
** File description:
** loop body any function it calls should be within the dynamic subfolded
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "hotload.h"

// return 0 to exit (exit code will be finit return value)
int loop(void *data)
{
    char c = 0;
    read(0, &c, 1);
    char *str = (char *)((data_t *)data)->mem;
    int *i =(int *) (str + 100);

    printf("%s\n", str);
    str[*i] = c;
    ++*i;
    if (strcmp(str, "exit\n") == 0 || *i >= 1024)
        return 0;
    if (c == '\n') {
        printf("Command: %s\n", str);
        memset(str, 0, 1024);
    }
    return 1;
}
