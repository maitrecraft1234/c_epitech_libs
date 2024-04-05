/*
** EPITECH PROJECT, 2024
** /home/vj/code/vicmem/src/vm_utils
** File description:
** memory management api
*/

#include <malloc.h>
#include "vicmem.h"

void *vm_taskinit(void *alloc, void (*destructor)(void *))
{
    vm_global_mmu_t *fetched = vm_mem_access(NULL);
    void *created_node = vm_create_node(alloc, destructor,
        fetched->current_scope);

    fetched->current_scope = created_node;
    return alloc;
}

void vm_scope_start(void)
{
    vm_global_mmu_t *current = vm_mem_access(NULL);
    vm_global_mmu_t *new = malloc(sizeof(vm_global_mmu_t));

    if (!new)
        return;
    new->prev_scope = current;
    new->current_scope = NULL;
    vm_mem_access(new);
}

void vm_scope_end(void)
{
    vm_global_mmu_t *current = vm_mem_access(NULL);

    if (!current)
        return;
    vm_scope_destroy(current->current_scope);
    vm_mem_access(current->prev_scope);
    free(current);
}

void *vm_nalloc(size_t size)
{
    void *alloc = malloc(size);
    vm_global_mmu_t *fetched = vm_mem_access(NULL);
    void *node;

    if (!fetched || !alloc) {
        free(alloc);
        return NULL;
    }
    node = vm_create_node(alloc, free, fetched->current_scope);
    if (node)
        fetched->current_scope = node;
    else
        return NULL;
    return alloc;
}
