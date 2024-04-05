/*
** EPITECH PROJECT, 2024
** src/vm_mem_node/mem_node_create
** File description:
** creating and destroying single node
*/

#include "vicmem.h"
#include <malloc.h>

vm_task_alloc_list_t *vm_create_node(void *data, void (*destroy) (void *),
    vm_task_alloc_list_t *prev_node)
{
    vm_task_alloc_list_t *node = malloc(sizeof(vm_task_alloc_list_t));

    if (!node) {
        destroy(data);
        return NULL;
    }
    node->block = data;
    node->destroy = destroy;
    node->next = prev_node;
    return node;
}

void vm_scope_destroy(vm_task_alloc_list_t *scope)
{
    void *tmp = NULL;

    for (; scope;) {
        tmp = scope;
        scope = scope->next;
        vm_destroy_node(tmp);
    }
}

//completely nukes the list
void vm_destroy_node(vm_task_alloc_list_t *node)
{
    if (node) {
        node->destroy(node->block);
    }
    free(node);
}
