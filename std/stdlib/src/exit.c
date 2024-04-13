/*
** EPITECH PROJECT, 2024
** /home/vj/code/std/stdlib/src/exit
** File description:
** exit function
*/

#ifdef __GNUC__
__attribute__((section(".text#")))
static const unsigned char exit_bytecode[] = {0x48, 0xc7, 0xc0,
    0x3c, 0x00, 0x00, 0x00, 0x0f, 0x05};

__attribute__((noreturn))
#endif

void lvl_sys_exit(volatile register int status)
{
    #ifdef __GNUC__
    ((void (*)())exit_bytecode)();
    __builtin_unreachable();
    #endif
    while (1);
}
