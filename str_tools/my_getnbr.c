/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** string to number
*/

#include "./tests/str_tools.h"
#include <stdio.h>

static int my_pow(int nb, int p)
{
    int r = 1;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    r = nb * my_pow(nb, (p - 1));
    if ((nb > 0 && r < 0) || (nb < 0 && p % 2 == 0 && r < 0))
        return (0);
    return (r);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int n = 0;
    int nb = 0;
    int p = 0;

    while (str &&str[i] != '\0') {
        if (str[i] == '-')
            n++;
        if (my_char_isnum(str[i]) == 1) {
            nb = (nb * 10 + (str[i] - '0'));
            p++;
            if (my_char_isnum(str[i + 1]) == 0)
                return (nb * my_pow(-1, n));
        }
        i++;
    }
    return (0);
}
