#include <criterion/criterion.h>
#include <string.h>
#include "lv_string.h"

Test(test_strcat, test_strcat)
{
    char s[100] = "yoabcyoayob";
    char st[100] = "yoabcyoayob";
    char const *tocat = "abc";

    cr_assert_str_eq(lv_strcat(s, tocat), strcat(st, tocat), "first it");
    cr_assert_str_eq(lv_strcat(s, tocat), strcat(s, tocat), "second it");
    cr_assert_str_eq(lv_strcat(s, tocat), strcat(s, tocat), "third it");
}
