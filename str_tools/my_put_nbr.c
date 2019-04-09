/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** put nbr
*/

#include <unistd.h>

static int my_istrlen(char const *src)
{
    int i = 0;

    while (src[i++] != '\0')
        ++i;
    return (i);
}

static void print_if_is_neg(int *nb)
{
    if (*nb < 0) {
        *nb = -*nb;
        write(1, "-", 1);
    }
}

static void my_put_base_nbr(int nb, char *base)
{
    if (nb / (my_istrlen(base) - 1) != 0)
        my_put_base_nbr(nb / (my_istrlen(base) -1) , base);
    write(1, &base[nb % (my_istrlen(base) - 1)], 1);
}

void my_put_nbr(int nb)
{
    print_if_is_neg(&nb);
    my_put_base_nbr(nb, "0123456789\0");
}
