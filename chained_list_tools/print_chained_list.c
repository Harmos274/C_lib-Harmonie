/*
** EPITECH PROJECT, 2019
** C lib
** File description:
** chained_list_displayer
*/

#include "../str_tools/tests/str_tools.h"
#include "./tests/chained_list_tools.h"
#include <string.h>
#include <malloc.h>


void display_chained_list(save_list_t *s_list, char *delim)
{
    save_list_t *discover = s_list;

    while (discover && discover->list && discover->list->next != NULL) {
        my_putstr(discover->list->str);
        my_putstr(delim);
        discover->list = discover->list->next;
    }
    free(discover);
}
