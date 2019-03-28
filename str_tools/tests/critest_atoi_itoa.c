/*
** EPITECH PROJECT, 2019
** test atoi and itoa
** File description:
** test for atoi (getnumber) and itoa
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "str_tools.h"
#include <unistd.h>

Test(my_getnumber, simple_test_pos_number)
{
    int str = my_getnbr("1234");

    cr_assert_eq(str, 1234);
}

Test(my_getnumber, simple_test_neg_number)
{
    int str = my_getnbr("-1234");

    cr_assert_eq(str, -1234);
}

Test(my_getnumber, NULL_string_test)
{
    int str = my_getnbr(NULL);

    cr_assert_eq(str, 0);
}

Test(my_itoa, simple_test_pos_digit_number)
{
    char *str = my_itoa(0);
    char *str_d = my_itoa(9);

    cr_assert_str_eq(str, "0");
    cr_assert_str_eq(str_d, "9");
    free(str);
    free(str_d);
}

Test(my_itoa, simple_test_neg_digit_number)
{
    char *str = my_itoa(-0);
    char *str_d = my_itoa(-9);

    cr_assert_str_eq(str, "0");
    cr_assert_str_eq(str_d, "-9");
    free(str);
    free(str_d);
}

Test(my_itoa, simple_test_pos_number)
{
    char *str = my_itoa(1234);

    cr_assert_str_eq(str, "1234");
    free(str);
}

Test(my_itoa, simple_test_neg_number)
{
    char *str = my_itoa(-1234);

    cr_assert_str_eq(str, "-1234");
    free(str);
}
