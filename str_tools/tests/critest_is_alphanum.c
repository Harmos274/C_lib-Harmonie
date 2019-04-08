/*
** EPITECH PROJECT, 2019
** minishell1 (cricri)
** File description:
** critest_str_to_wordarr
*/

#include <criterion/criterion.h>
#include <stdio.h>
#include "str_tools.h"
#include <unistd.h>

Test(my_char_isalpha, simple_test_without_trap)
{
    char c = 'a';

    cr_assert_eq(my_char_isalpha(c), 1);
}

Test(my_char_isalpha, simple_fail_test_without_trap)
{
    char c = '1';

    cr_assert_eq(my_char_isalpha(c), 0);
}

Test(my_char_isnum, simple_test_without_trap)
{
    char c = '1';

    cr_assert_eq(my_char_isnum(c), 1);
}

Test(my_char_isnum, simple_fail_test_without_trap)
{
    char c = 'a';

    cr_assert_eq(my_char_isnum(c), 0);
}

Test(my_str_isalpha, simple_test_whithout_trap)
{
    char *str = "abcdef";

    cr_assert_eq(my_str_isalpha(str), 1);
}

Test(my_str_isalpha, simple_fail_test_whithout_trap)
{
    char *str = "12345";

    cr_assert_eq(my_str_isalpha(str), 0);
}

Test(my_str_isnum, simple_test_whithout_trap)
{
    char *str = "12356";

    cr_assert_eq(my_str_isnum(str), 1);
}

Test(my_str_isnum, simple_fail_test_whithout_trap)
{
    char *str = "abcdef";

    cr_assert_eq(my_str_isnum(str), 0);
}
