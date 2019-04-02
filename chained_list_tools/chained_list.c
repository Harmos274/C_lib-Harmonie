/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** chained_list gestion
*/

#include "../include/bs_pushswap.h"

save_list_t *init(int nbr)
{
    save_list_t *list = malloc(sizeof(*list));
    int_list_t *int_list = malloc(sizeof(*int_list));

    if (list == NULL || int_list == NULL)
        return (EXIT);
    int_list->nbr = nbr;
    int_list->next = NULL;
    list->first = int_list;
    list->nbr_elmnt = 1;
    return (list);
}

void add_elmnt(save_list_t *list, int new_nbr)
{
    int_list_t *new = malloc(sizeof(*new));

    if (list == NULL || new == NULL)
        return ;
    new->nbr = new_nbr;
    new->next = list->first;
    list->first = new;
    list->nbr_elmnt = list->nbr_elmnt + 1;
}

void supr_elmnt(save_list_t *list)
{
    int_list_t *supr = malloc(sizeof(*supr));

    if (list == NULL)
        return ;
    if (list->first != NULL) {
        supr = list->first;
        list->first = list->first->next;
        free(supr);
        list->nbr_elmnt = list->nbr_elmnt - 1;
    }
}

void print_list(save_list_t *list)
{
    int_list_t *actual = malloc(sizeof(*actual));

    if (list && list == NULL)
        return ;
    actual = list->first;
    while (actual && actual != NULL) {
        my_put_nbr(actual->nbr);
        my_putstr(" ->");
        actual = actual->next;
    }
    my_putstr("NULL\n");
    my_putstr("nbr chainons = ");
    my_put_nbr(list->nbr_elmnt);
    my_putstr("\n");
}
