/*
** EPITECH PROJECT, 2019
** test atoi and itoa
** File description:
** test for atoi (getnumber) and itoa
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "str_tools.h"

Test(my_str_rewrite, simple_test)
{
    char *str = my_strdup("abdcdefghi");

    my_str_rewrite(&str, "lol", 3);
    cr_assert_str_eq(str, "lolcdefghi");
}

Test(my_str_rewrite, simple_test_but_n_lower_than_strlen)
{
    char *str = my_strdup("abdcdefghi");

    my_str_rewrite(&str, "lolilo", 3);
    cr_assert_str_eq(str, "lolcdefghi");
}

Test(my_str_rewrite, simple_test_but_n_highter_than_strlen)
{
    char *str = my_strdup("abcdefghi");

    my_str_rewrite(&str, "lol", 0);
    cr_assert_str_eq(str, "abcdefghi");
}
