#include <criterion/criterion.h>
#include <string.h>
#include "lvstrings.h"

Test(test_memset_easy, test_memset)
{
    char dr[100];
    char dt[100];
    int value = 1;

    cr_assert_str_eq(lvs_memset(dr, value, 100), memset(dt, value, 100));
}

Test(test_memset_weird, test_memset)
{
    char dr[100];
    char dt[100];
    int value = 1000;

    cr_assert_str_eq(lvs_memset(dr, value, 100), memset(dt, value, 100));
}
