/*
** EPITECH PROJECT, 2019
** lemin
** File description:
** mae map from file
*/

#include "basic_lib.h"
#include "map_tester.h"
#include "chained_map.h"
#include "display_map.h"
#include <malloc.h>
#include <stdio.h>
#include <unistd.h>

int init_list(save_list_t *map, char *buffer)
{
    chained_map_t *first = malloc(sizeof(*first));

    if (first == NULL)
        return (84);
    first->line = my_strdup(buffer);
    first->next = NULL;
    map->first = first;
    map->nbr_chain = 1;
    return (0);
}

int add_list(save_list_t *map, char *buffer)
{
    chained_map_t *node = malloc(sizeof(*node));
    chained_map_t *discover = map->first;

    if (node == NULL)
        return (84);
    node->line = buffer;
    node->next = NULL;
    while (discover && discover->next != NULL)
        discover = discover->next;
    discover->next = node;
    map->nbr_chain += 1;
    return (0);
}

save_list_t *make_chained_map(void)
{
    save_list_t *map = malloc(sizeof(*map));
    char *buffer = NULL;
    size_t n = 0;

    if (map == NULL)
        return (map);
    if (getline(&buffer, &n, stdin) >= 0) {
        if (init_list(map, buffer) == 84)
            return (NULL);
        buffer = NULL;
        n = 0;
    }
    while (getline(&buffer, &n, stdin) > 0) {
        if (add_list(map, buffer) == 84)
            return (NULL);
        buffer = NULL;
        n = 0;
    }
    return (map);
}

char **make_map(save_list_t *saved_map)
{
    char **map = malloc(sizeof(char *) * (saved_map->nbr_chain + 1));
    size_t i = 0;

    while (saved_map && saved_map->first->next != NULL) {
        map[i] = saved_map->first->line;
        saved_map->first = saved_map->first->next;
        ++i;
    }
    map[i] = saved_map->first->line;
    return (map);
}
