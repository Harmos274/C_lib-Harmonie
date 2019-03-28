/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_strdup
*/

#include <stddef.h>
#include <stdlib.h>
#include "./tests/str_tools.h"

char *my_strdup(char const *str)
{
    char *strduped = malloc(sizeof(char) * (my_strlen(str) + 1));
    size_t i = 0;

    if (!str || strduped == NULL) {
        free(strduped);
        return (NULL);
    }
    while (str && str[i] != '\0') {
        strduped[i] = str[i];
        ++i;
    }
    strduped[i] = '\0';
    return (strduped);
}
