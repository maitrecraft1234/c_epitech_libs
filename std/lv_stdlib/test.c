#include <stdio.h>
#include <stdlib.h>

#include <stddef.h>

double lv_atof(char const *str)
{
    char sign = str[0] == '-' ? -1 : 1;
    double ret = 0;
    size_t decimals = 10;

    str = (*str == '-' || *str == '+') ? str + 1 : str;
    for (; *str && *str != '.'; ++str) {
        ret *= 10;
        ret += *str - '0';
    }
    for (str = *str == '.' ? str + 1 : str; *str; ++str) {
        ret += (*str - '0') / (double)decimals;
        decimals *= 10;
    }
    return ret * sign;
}

int lv_atoi(char const *str)
{
    char sign = str[0] == '-' ? -1 : 1;
    int ret = 0;
    size_t len;

    str = (*str == '-' || *str == '+') ? str + 1 : str;
    for (; *str; ++str) {
        ret *= 10;
        ret += *str - '0';
    }
    return ret * sign;
}


int main(int ac, char **av) {
    printf("%d\n", atoi(av[1]));
    printf("%d\n", lv_atoi(av[1]));
    printf("%f\n", lv_atof(av[1]));
    printf("%f\n", atof(av[1]));
  return 0;
}
