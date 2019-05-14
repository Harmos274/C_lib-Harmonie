/*
** EPITECH PROJECT, 2019
** C lib
** File description:
** tab set
*/

#include <stddef.h>
#include <unistd.h>
#include "malloc.h"

static void nullify_to(void *tabptr, size_t limit, int do_free)
{
    void **tab = (void **)(tabptr);
    size_t i = 0;

    while (i != limit + 1) {
        if (do_free == 1)
            free(tab[i]);
        tab[i] = NULL;
        ++i;
    }
    if (i == 0 && do_free == 1)
        free(tab);
}

static void set_the_line(char *str, const size_t x, char c)
{
    size_t i = 0;

    while (i != x) {
        str[i] = c;
        ++i;
    }
    str[i] = '\0';
}

static int set_the_tab(char **tab, const size_t x, const size_t y, char c)
{
    size_t i = 0;

    while (i != y) {
        tab[i] = malloc(sizeof(char) * (x + 1));
        if (!tab[i]) {
            nullify_to(tab, i, 1);
            return (-1);
        }
        set_the_line(tab[i], x, c);
        ++i;
    }
    tab[y] = NULL;
    return (0);
}

char **tab_set(const size_t x, const size_t y, char c)
{
    char **tab = malloc(sizeof(char *) * (y + 1));

    if (!tab) {
        write(2, "Allocation error: tab not found.\n", 33);
        return (tab);
    }
    if (set_the_tab(tab, x, y, c) == -1) {
        free(tab);
        return (NULL);
    }
    return (tab);
}
