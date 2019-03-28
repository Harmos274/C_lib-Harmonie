/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_strncpy
*/

#include <stddef.h>

void my_str_rewrite(char **source, char *rew, size_t len)
{
    size_t i = 0;

    while ((i < len) && ((*source)[i] != '\0') && (rew[i] != '\0')) {
        (*source)[i] = rew[i];
        ++i;
    }
}

char *my_strncpy(char *dest, char *src, size_t n)
{
    size_t i = 0;

    while ((i < n) && (src[i] != '\0')) {
        dest[i] = src[i];
        ++i;
    }
    while (i < n) {
        dest[i] = '\0';
        ++i;
    }
    return (dest);
}
