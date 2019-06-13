/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_tablen
*/

#include <stddef.h>
#include <unistd.h>

ssize_t my_tablen(void *tabptr)
{
    size_t i = 0;
    void **tab = (void **)tabptr;

    if (!tab) {
        return (-1);
    }
    while (tab[i] != NULL) {
        ++i;
    }
    return (i);
}
