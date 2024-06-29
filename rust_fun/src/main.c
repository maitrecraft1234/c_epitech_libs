#include <fcntl.h>
#include <errno.h>
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "rust/libc.h"
#include "rust/fn_types.h"
#include "rust/strings.h"

FN(test, (int a), int,
    if (a == 0)
        return 0;
    printf("a = %d in function %s\n", a, __FUNCTION__);
    test(a - 1);
)

    void *x = (void *)0xAFD120;

void find_match(void *from, void *to, uintptr_t match)
{
    uintptr_t *p = from;
    uintptr_t *end = to;

    printf("from = %p, to = %p\n", from, to);
    printf(" from - end = %ld\n", end - p);
    while (p < end) {
        if ((uintptr_t)p % 1000000 == 0)
            printf("p = %p\n", p);
        if (*p == match) {
            printf("matches ");
            printf("p = %p\n", p);
        }
        p++;
    }
}

uintptr_t get_first_map_addr(void)
{
    FILE *f = fopen("/proc/self/maps", "r");
    char buf[256];
    uintptr_t addr;

    if (!f)
        return 0;
    if (!fgets(buf, 256, f))
        return 0;
    fclose(f);
    sscanf(buf, "%lx", &addr);
    return addr;
}

uintptr_t get_last_map_addr(void)
{
    FILE *f = fopen("/proc/self/maps", "r");
    char buf[256];
    uintptr_t addr;
    size_t i = 0;

    if (!f)
        return 0;
    while (fgets(buf, 256, f)) {
    }
    fclose(f);
    while (i[buf] != '-')
        i++;
    sscanf(buf+i+1, "%lx", &addr);
    return addr;
}

void print_all_mmap(void)
{
    FILE *f = fopen("/proc/self/maps", "r");
    char buf[256];

    while (fgets(buf, 256, f)) {
        printf("%s", buf);
    }
    fclose(f);
    printf("First map addr = %lx\n", get_first_map_addr());
    printf("Last map addr = %lx\n", get_last_map_addr());
}

void find_heap(void *match) //mmap segments are not included
{
    void *p = sbrk(0);
    void *end = (void *)find_heap;

    puts("Finding on heap");
    find_match(p, end, (uintptr_t)match);
}

void find_on_mem(void *match)
{
    uintptr_t *p = (uintptr_t *)get_first_map_addr() + 0x1000;
    uintptr_t *end = (uintptr_t *)get_last_map_addr();

    puts("Finding on memory");
    printf("p = %p, end = %p\n", *p, *end);
    find_match(p, end, (uintptr_t)match);
}

const char a[] = "Hello world\n";
char *a2 = "Hello world\n";
char a3[] = "Hello world\n";

void find_on_stack(void *match, void *stack_base)
{
    uintptr_t *p = stack_base;
    uintptr_t *end = __builtin_frame_address(0);

    puts("Finding on stack");
    find_match(end, p, (uintptr_t)match);
}
#include <stdlib.h>
int main(int ac, char **av)
{
    void * a = __builtin_frame_address(0);
    void *x = (void *)0xAFD120;

    printf("malloc %p\n", malloc(400000));
    printf("global = %p\n", &a);
    printf("global = %p\n", &a2);
    printf("global = %p\n", &a3);
    print_all_mmap();
    void *brak = sbrk(0);
    brk(0);
    void *brak2 = sbrk(0);
    brk(brak);
    printf("break = %p\n", brak);
    printf("break = %p\n", brak2);
    find_on_stack(x, a);
    find_on_mem(x);
}

/* int main2(int ac, char **av) */
/* { */
/*     LET a = test(3); */
/*     if (ac != 2) */
/*         return ((int (*)(void))&&label)(); */
/*  */
/*     printf("Opening file %s\n", av[1]); */
/*     LET res = UNWRAP(open_wrap(av[1], O_RDONLY)); */
/*     close(res); */
/* label: */
/*     printf("Done\n"); */
/*     return 0; */
/* } */
