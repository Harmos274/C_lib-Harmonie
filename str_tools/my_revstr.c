/*
** EPITECH PROJECT, 2018
** my_revstr.c
** File description:
** reverses a string
*/

#include <stdio.h>
#include <stdlib.h>
#include "./tests/str_tools.h"

char *my_revstr(char *str)
{
    size_t i = my_strlen(str);
    size_t e = 0;
    char *revstr = malloc(sizeof(char) * (i + 1));

    if (revstr == NULL)
        return (NULL);
    while (i != 0) {
        revstr[e] = str[i - 1];
        ++e;
        --i;
    }
    revstr[e] = '\0';
    return (revstr);
}
