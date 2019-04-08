/*
** EPITECH PROJECT, 2019
** lemin
** File description:
** mae map from file
*/

#include <malloc.h>
#include <stddef.h>
#include "../str_tools/tests/str_tools.h"
#include "./tests/chained_list_tools.h"

int add_start_chain(save_list_t *s_list, char *str)
{
    chained_list_t *chain = malloc(sizeof(*chain));

    if (!chain)
        return (-1);
    chain->str = my_strdup(str);
    if (chain->str == NULL) {
        free(chain);
        return (-1);
    }
    chain->next = s_list->list;
    s_list->list = chain;
    s_list->nbr_chain += 1;
    return (0);
}

int add_last_chain(save_list_t *s_list, char *str)
{
    chained_list_t *chain = malloc(sizeof(*chain));
    chained_list_t *discover = s_list->list;

    if (!chain)
        return (-1);
    chain->str = my_strdup(str);
    chain->next = NULL;
    while (discover && discover->next != NULL)
        discover = discover->next;
    if (!discover)
        s_list->list = chain;
    else
        discover->next = chain;
    s_list->nbr_chain += 1;
    return (0);
}

save_list_t *create_saved_list(void)
{
    save_list_t *s_list = malloc(sizeof(*s_list));

    if (!s_list)
        return (NULL);
    s_list->list = malloc(sizeof(chained_list_t));
    if (!s_list->list) {
        free(s_list);
        return (NULL);
    }
    s_list->list = NULL;
    s_list->nbr_chain = 0;
    return (s_list);
}
