/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_tabdup
*/

#include <stddef.h>
#include <malloc.h>
#include "./tests/tab_tools.h"

char **my_tabdup(char **tab)
{
    size_t tablen = my_tablen(tab);
    char **tabduped = malloc(sizeof(char *) * (tablen + 1));
    size_t i = 0;

    if (!tabduped || !tab) {
        nullify_from((void **)tabduped, 0, 1);
        free(tabduped);
        return (NULL);
    }
    while (tab[i] != NULL && i != tablen) {
        tabduped[i] = my_strdup(tab[i]);
        ++i;
    }
    tabduped[i] = NULL;
    return (tabduped);
}
