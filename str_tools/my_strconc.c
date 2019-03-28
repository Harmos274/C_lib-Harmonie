/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_strconc
*/

#include "./tests/str_tools.h"
#include <malloc.h>

static char *my_str_cfill(size_t size)
{
    char *str = malloc(size);
    size_t i = 0;

    if (str == NULL)
        return (NULL);
    while (i != size) {
        str[i] = '\0';
        i++;
    }
    return (str);
}

char *my_strconc(char *left, char *env_line)
{
    char *str = my_str_cfill(sizeof(char) *
    (my_strlen(left) + my_strlen(env_line) + 1));
    size_t i = 0;
    size_t k = 0;

    if (str == NULL || (my_strlen(left) == -1 || my_strlen(env_line) == -1))
        return (NULL);
    while (left && left[i] != '\0') {
        str[i] = left[i];
        i++;
    }
    while (env_line && env_line[k] != '\0') {
        str[i] = env_line[k];
        i++;
        k++;
    }
    return (str);
}
