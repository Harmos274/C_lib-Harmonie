/*
** EPITECH PROJECT, 2019
** C_lib
** File description:
** printab
*/

#include <stddef.h>
#include "../str_tools/tests/str_tools.h"

void printab(char **tab, char const c)
{
    size_t y = 0;

    while (tab && tab[y] != NULL) {
        my_putstr(tab[y]);
        my_putstr(&c);
        ++y;
    }
}
