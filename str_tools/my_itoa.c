/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_revatoi
*/

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

static size_t my_strintlen(char const *str)
{
    size_t i = 0;

    while (str && (str[i] != '\0')) {
        ++i;
    }
    return (i);
}

static char *my_revnbr(char *str)
{
    size_t i = my_strintlen(str);
    size_t e = 0;
    char *revstr = malloc(sizeof(char) * (i + 1));
    size_t limit = 0;

    if (str[0] == '-') {
        revstr[e++] = '-';
        limit = 1;
    }
    if (revstr == NULL)
        return (NULL);
    while (i != limit) {
        revstr[e] = str[i - 1];
        ++e;
        --i;
    }
    revstr[e] = '\0';
    free(str);
    return (revstr);
}

static size_t my_intlen(int nbr)
{
    size_t x = 10;
    size_t i = 0;

    if (nbr < 0) {
        nbr = -nbr;
        ++i;
    }
    while ((size_t)nbr % x != (size_t)nbr) {
        x *= 10;
        ++i;
    }
    return (i + 1);
}

static void neg_tester(int *nbr, char **str, size_t *i)
{
    if (*nbr < 0) {
        *nbr = -*nbr;
        (*str)[*i] = '-';
        *i += 1;
    }
}

char *my_itoa(int nbr)
{
    char *str = malloc(sizeof(char) * (my_intlen(nbr) + 1));
    size_t x = 10;
    size_t i = 0;
    size_t cc = 0;

    str[my_intlen(nbr)] = '\0';
    neg_tester(&nbr, &str, &i);
    if (str == NULL)
        return (NULL);
    while ((cc = (size_t)nbr % x) != (size_t)nbr) {
        if (cc >= 10)
            cc /= x/10;
        str[i] = cc + '0';
        x *= 10;
        ++i;
    }
    str[i] = nbr / (x / 10) + '0';
    str = my_revnbr(str);
    return (str);
}
