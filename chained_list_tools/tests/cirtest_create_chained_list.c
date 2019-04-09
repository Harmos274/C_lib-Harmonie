/*
** EPITECH PROJECT, 2019
** C lib
** File description:
** critest_chained_list
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <unistd.h>
#include "./chained_list_tools.h"
#include "../../str_tools/tests/str_tools.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(create_chained_list, simple_test)
{
    save_list_t *s_list = create_saved_list();

    cr_assert(s_list);
}

Test(add_start_chain, simple_test, .init = redirect_all_std)
{
    save_list_t *s_list = create_saved_list();

    cr_assert(s_list);
    cr_assert_eq(add_start_chain(s_list, "lol"), 0);
    my_putstr(s_list->list->str);
    my_putstr("\n");
    cr_assert_stdout_eq_str("lol\n");
}

Test(add_last_chain, simple_test, .init = redirect_all_std)
{
    save_list_t *s_list = create_saved_list();

    cr_assert(s_list);
    cr_assert_eq(add_last_chain(s_list, "lol"), 0);
    my_putstr(s_list->list->str);
    cr_assert_stdout_eq_str("lol");
}

Test(supr_list, simple_test)
{
    save_list_t *s_list = create_saved_list();

    cr_assert(s_list);
    cr_assert_eq(add_last_chain(s_list, "1"), 0);
    cr_assert_eq(add_last_chain(s_list, "2"), 0);
    cr_assert_eq(add_last_chain(s_list, "3"), 0);
    cr_assert_eq(add_last_chain(s_list, "4"), 0);
    cr_assert_eq(supr_save_list(&s_list), 0);
    cr_assert(!s_list);
}
