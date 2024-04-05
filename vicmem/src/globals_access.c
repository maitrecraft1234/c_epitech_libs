/*
** EPITECH PROJECT, 2024
** /home/vj/code/vicmem/src/globals_access
** File description:
** accessing globals
*/

#include "vicmem.h"
#include <stddef.h>

vm_global_mmu_t *vm_mem_access(vm_global_mmu_t *signal)
{
    static vm_global_mmu_t *vm_mem = NULL;

    if (signal)
        vm_mem = signal;
    return vm_mem;
}
