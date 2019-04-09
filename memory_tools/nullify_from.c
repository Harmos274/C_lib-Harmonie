/*
** EPITECH PROJECT, 2019
** lib
** File description:
** nullify_from
*/

#include <stddef.h>
#include <malloc.h>

void nullify_from(void *tabptr, size_t i, int do_free)
{
    void **tab = (void**)(tabptr);

    while (tab && tab[i] != NULL) {
        if (do_free == 1)
            free(tab[i]);
        tab[i] = NULL;
        ++i;
    }
    if (i == 0 && do_free == 1)
        free(tab);
}

void nullify_to(void *tabptr, size_t limit, int do_free)
{
    void **tab = (void**)(tabptr);
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
