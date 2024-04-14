#include <criterion/criterion.h>
#include <string.h>
#include "lv_string.h"

Test(test_strtok, test_strtok)
{
    char s[] = "yoabcyoayob";
    char st[] = "yoabcyoayob";
    char const *delim = "abc";

    cr_assert_str_eq(lv_strtok(s, delim), strtok(st, delim), "first it");
    cr_assert_str_eq(lv_strtok(NULL, delim), strtok(NULL, delim), "second it");
    cr_assert_str_eq(lv_strtok(NULL, delim), strtok(NULL, delim), "third it");
}
