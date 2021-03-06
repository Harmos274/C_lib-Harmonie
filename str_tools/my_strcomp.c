/*
** EPITECH PROJECT, 2019
** C lib str tools
** File description:
** my_strcomp
*/

#include "./tests/str_tools.h"
#include <stddef.h>

int my_strcomp(char *source, char *compared)
{
    size_t i = 0;

    if (my_strlen(source) != my_strlen(compared))
        return (0);
    while (source && source[i] != '\0') {
        if (source[i] != compared[i])
            return (0);
        ++i;
    }
    return (1);
}
