/*
** EPITECH PROJECT, 2019
** C_lib
** File description:
** rot printab
*/

#include "../str_tools/tests/str_tools.h"
#include "./tests/tab_tools.h"
#include <malloc.h>

int rotate_90_deg(char ***tab)
{
    ssize_t y = 0;
    ssize_t x = 0;
    ssize_t t_len = my_tablen(*tab);
    ssize_t s_len = my_strlen((*tab)[0]);
    char **new_tab = tab_set(t_len, s_len, '0');

    if (!new_tab)
        return (-1);
    while (x != s_len) {
        while (y != t_len) {
            new_tab[x][y] = (*tab)[t_len - 1 - y][x];
            ++y;
        }
        y = 0;
        ++x;
    }
    nullify_from(*tab, 0, 1);
    free(*tab);
    *tab = new_tab;
    return (0);
}

int rotate_tab(char ***tab, int rot)
{
    size_t loop = ((rot % 360) / 90);

    if (!tab)
        return (-1);
    while (loop > 0) {
        if (rotate_90_deg(tab) == -1)
            return (-1);
        --loop;
    }
    return (0);
}
