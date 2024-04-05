/*
** EPITECH PROJECT, 2024
** /home/vj/code/vicmem/tests/main
** File description:
** tester with simple usage, will do automated tests later
*/

#include "vicmem.h"
#include <stdio.h>

int main(void)
{

    char *test = vm_nalloc(sizeof(char) * 10);
    char *test2 = vm_nalloc(sizeof(char) * 14);
    char **test3 = vm_nalloc(sizeof(char *) * 10);

 
    vm_scope_start();

    char *tests = vm_nalloc(10);
    vm_scope_start();
    char *tasts __attribute__((unused)) = vm_nalloc(10);
    vm_scope_start();
    vm_scope_end();
    //printf("%s\n",tests);
    vm_scope_end();
    puts("test\n");

}
