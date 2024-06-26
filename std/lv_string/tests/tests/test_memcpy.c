#include <criterion/criterion.h>
#include <string.h>
#include "lv_string.h"

Test(test_memcpy, test_memcpy)
{
    char dr[100];
    char dt[100];
    char const src[100] = {'a'};

    cr_assert_str_eq(memcpy(dr, src, 100), lv_memcpy(dt, src, 100));
}
