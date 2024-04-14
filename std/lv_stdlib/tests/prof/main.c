#include <lv_stdlib.h>
#include <stdio.h>

int main(void)
{
    puts("before exit");
    lv_sys_exit(69);
    puts("after exit (task failed)");
}
