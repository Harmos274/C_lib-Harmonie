/*
** EPITECH PROJECT, 2019
** lemin
** File description:
** mae map from file
*/

#include "./tests/chained_list_tools.h"
#include <malloc.h>
#include <stdio.h>
#include <unistd.h>

char **my_chlist_to_tab(save_list_t *s_list)
{
    char **map = malloc(sizeof(char *) * (s_list->nbr_chain + 1));
    size_t i = 0;

    map[s_list->nbr_chain] = NULL;
    while (s_list && s_list->list != NULL) {
        map[i] = s_list->list->str;
        s_list->list = s_list->list->next;
        ++i;
    }
    return (map);
}
