/*
** EPITECH PROJECT, 2019
** criterion test
** File description:
** my_str_split
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "str_tools.h"
#include <unistd.h>
#include <stdio.h>

Test(my_str_split, simple_space_separator)
{
    char *str = "Roses are red, violet are blue, Omae wa mo shindeiru\0";
    char **tab = my_str_split(str, ' ');
    int i = 0;

    cr_redirect_stdout();
    cr_assert(tab != NULL);
    while (tab[i] != NULL) {
        write(1, tab[i], my_strlen(tab[i]));
        write(1, "\n", 1);
        ++i;
    }
    cr_assert_stdout_eq_str(
        "Roses\nare\nred,\nviolet\nare\nblue,\nOmae\nwa\nmo\nshindeiru\n");
}

Test(my_str_split, multiple_space_separator)
{
    char *str = "Roses are   red,   violet are blue, Omae wa mo shindeiru\0";
    char **tab = my_str_split(str, ' ');
    int i = 0;

    cr_redirect_stdout();
    cr_assert(tab != NULL);
    while (tab[i] != NULL) {
        write(1, tab[i], my_strlen(tab[i]));
        write(1, "\n", 1);
        ++i;
    }
    cr_assert_stdout_eq_str(
        "Roses\nare\nred,\nviolet\nare\nblue,\nOmae\nwa\nmo\nshindeiru\n");
}

Test(my_str_split, null_string)
{
    char *str = NULL;
    char **tab = my_str_split(str, ' ');

    cr_assert_eq(tab, NULL);
}
