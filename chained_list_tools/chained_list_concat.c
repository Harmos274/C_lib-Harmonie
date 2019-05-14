/*
** EPITECH PROJECT, 2019
** C lib
** File description:
** concat two chained list
*/

#include "./tests/chained_list_tools.h"
#include <stddef.h>

int chain_counter(chained_list_t *list)
{
    chained_list_t *discover = list;
    int i = 0;

    if (!list)
        return (-1);
    while (discover->next != NULL) {
        discover = discover->next;
        ++i;
    }
    return (i);
}

int chained_list_end_concat(save_list_t *s_list, chained_list_t *right_list)
{
    chained_list_t *discover = s_list->list;

    if (!s_list || !right_list)
        return (-1);
    while (discover->next != NULL)
        discover = discover->next;
    discover->next = right_list;
    s_list->nbr_chain += chain_counter(right_list);
    return (0);
}

int chained_list_start_concat(save_list_t *s_list, chained_list_t *left_list)
{
    chained_list_t *discover = left_list;
    int i = 0;

    if (!s_list || !left_list)
        return (-1);
    while (discover->next != NULL) {
        discover = discover->next;
        ++i;
    }
    discover->next = s_list->list;
    s_list->list = discover;
    s_list->nbr_chain += i;
    return (0);
}
