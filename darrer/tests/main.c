/*
** EPITECH PROJECT, 2024
** /home/vj/code/vicmem/tests/main
** File description:
** tester with simple usage, will do automated tests later
*/

#include <stdio.h>
#include <string.h>
#include "darrer.h"

int main(void)
{
    char *test_daray = da_create(1);

    DAC(test_daray, 0) = 'a';
    DAC(test_daray, 1) = 'a';
    DAC(test_daray, 2) = 'a';
    DAC(test_daray, 3) = 'a';
    DAC(test_daray, 4) = 'a';
    test_daray = da_push(test_daray, "test !", sizeof("test !") - 1);
    test_daray = da_push(test_daray, "test !", sizeof("test !"));


    puts(test_daray);
    printf("len = %ld\n", DA_LEN(test_daray));
    da_destroy(test_daray);
}
