/*
** EPITECH PROJECT, 2018
** C lib
** File description:
** chained_list gestion
*/

#include "./tests/chained_list_tools.h"
#include <malloc.h>

int supr_all_elements(save_list_t *s_list)
{
    chained_list_t *current = NULL;
    chained_list_t *next = NULL;

    if (!s_list)
        return (-1);
    current = s_list->list;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    s_list->list = NULL;
    return (0);
}

int supr_first_element(save_list_t *s_list)
{
    chained_list_t *supr = NULL;

    if (!s_list)
        return (-1);
    if (s_list->list != NULL) {
        supr = s_list->list;
        s_list->list = s_list->list->next;
        free(supr);
        s_list->nbr_chain -= 1;
    }
    return (0);
}

int supr_last_element(save_list_t *s_list)
{
    chained_list_t *supr = NULL;

    if (!s_list) {
        return (-1);
    }
    supr = s_list->list;
    while (supr->next->next != NULL)
        supr = supr->next;
    free(supr->next);
    supr->next = NULL;
    s_list->nbr_chain -= 1;
    return (0);
}

int supr_save_list(save_list_t **s_list)
{
    if (!s_list)
        return (-1);
    if (supr_all_elements(*(s_list)) == -1)
        return (-1);
    free(*(s_list));
    *(s_list) = NULL;
    return (0);
}
