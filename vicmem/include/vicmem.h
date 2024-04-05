/*
** EPITECH PROJECT, 2024
** /home/vj/code/vicmem/include/vicmem
** File description:
** header for vicmem
*/

#pragma once
    #include <stddef.h>

typedef struct vm_task_alloc_list_s {
    void *block;
    void (*destroy) (void *);
    struct vm_task_alloc_list_s *next;
} vm_task_alloc_list_t;

typedef struct vm_global_mmu_s {
    struct vm_global_mmu_s *prev_scope;
    vm_task_alloc_list_t *current_scope;
} vm_global_mmu_t;

//acces to global vm memory, accessible but shouldn't be used
vm_global_mmu_t *vm_mem_access(vm_global_mmu_t *signal);

//vm_list node handling can be used but isn't the point of the lib
void vm_destroy_node(vm_task_alloc_list_t *node);
vm_task_alloc_list_t *vm_create_node(void *data, void (*destroy) (void *),
    vm_task_alloc_list_t *prev_node);

void vm_scope_destroy(vm_task_alloc_list_t *scope);

//api for normal and custom allocations.
void vm_init(void)__attribute__((constructor(1000)));
void vm_finit(void)__attribute__((destructor));
void *vm_nalloc(size_t size);
void vm_scope_start(void);
void vm_scope_end(void);
