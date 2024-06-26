/*
** EPITECH PROJECT, 2024
** /home/vj/code/std/stdlib/src/exit
** File description:
** exit function
*/

#include <stddef.h>
#include "lv_stdlib.h"
#include "lvi_stdlib.h"

#if defined(__GNUC__) && defined(__x86_64__)
__attribute__((section(".text#")))
static const unsigned char lvi_exit_bytecode[] = {0x48, 0xc7, 0xc0,
    0x3c, 0x00, 0x00, 0x00, 0x0f, 0x05};

__attribute__((noreturn))
#elif defined(__GNUC__)
static int main_fn(int ac, __attibute__((unused))char **av) {
    return ac;
}
#endif

void lv_sys_exit(volatile register int status)
{
    #if defined(__GNUC__) && defined(__x86_64__)
    ((void (*)())lvi_exit_bytecode)();
    __builtin_unreachable();
    #elif defined(__GNUC__)
    __libc_start_main(main_fn, status, NULL, NULL, NULL, NULL, NULL);
    __builtin_unreachable();
    #endif
    while (1);
}

static struct lvi_atexit_stack_s {
    void (**functions)(void);
    size_t size;
    size_t capacity;
}
*lvi_atexit_stack_access(void (*request)(void))
{
    static struct lvi_atexit_stack_s static_stack = {0};

    if (!request)
        return &static_stack;
    if (!static_stack.functions) {
        static_stack.capacity = 1;
        static_stack.functions = lv_malloc(
            sizeof(*static_stack.functions) * static_stack.capacity);
    } else if (static_stack.size == static_stack.capacity) {
        static_stack.capacity = static_stack.capacity * 2;
        static_stack.functions = lv_realloc(static_stack.functions,
                sizeof(*static_stack.functions) * static_stack.capacity);
    }
    static_stack.functions[static_stack.size] = request;
    ++static_stack.size;
    return &static_stack;
}

__attribute__((noreturn))
void lv_exit(int status)
{
    struct lvi_atexit_stack_s *fn_stack = lvi_atexit_stack_access(NULL);

    for (size_t i = fn_stack->size; i > 0; --i)
        fn_stack->functions[i - 1]();
    lv_free(fn_stack->functions);
    lv_sys_exit(status);
}

void lv_at_exit(void (*function)(void))
{
    if (!function)
        return;
    lvi_atexit_stack_access(function);
}
