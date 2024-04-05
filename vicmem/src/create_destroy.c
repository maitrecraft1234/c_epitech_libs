/*
** EPITECH PROJECT, 2024
** /home/vj/code/vicmem/src/create_destroy
** File description:
** creation and deletion for mem manager
*/

#include "vicmem.h"
#include <malloc.h>

void vm_init(void)
{
    vm_global_mmu_t *global_scope = malloc(sizeof(vm_global_mmu_t));

    if (!global_scope)
        return;
    global_scope->current_scope = NULL;
    global_scope->prev_scope = NULL;
    (void)vm_mem_access(global_scope);
}

void vm_finit(void)
{
    vm_global_mmu_t *global_scope = vm_mem_access(NULL);
    void *tmp = NULL;

    for (vm_global_mmu_t *loop = global_scope; loop;) {
        vm_scope_destroy(loop->current_scope);
        tmp = loop;
        loop = loop->prev_scope;
        free(tmp);
    }
}
