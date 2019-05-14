/*
** EPITECH PROJECT, 2019
** C_lib
** File description:
** printab
*/

#include <stddef.h>
#include "../str_tools/tests/str_tools.h"

void printab(char **tab)
{
    size_t y = 0;

    while (tab && tab[y] != NULL) {
        write(1, tab[y], my_strlen(tab[y]));
        write(1, "\n", 1);
        ++y;
    }
}
