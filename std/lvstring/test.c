#include <stdio.h>
#include <malloc.h>
#include "lvstrings.h"

int main(void)
{
    char *a = "abcdef";
    LVS_STRDUPA(b, =, a);

    printf("a = %s & %p, b = %s & %p\n", a, &a, b, &b);
}
