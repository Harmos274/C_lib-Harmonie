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

save_list_t *create_test_saved_list(void)
{
    save_list_t *s_list = create_saved_list();

    if (!s_list)
        return (NULL);
    if ((add_start_chain(s_list, "lol") == -1)
        || (add_start_chain(s_list, "lal") == -1))
            return (NULL);
    return (s_list);
}

Test(display_chained_list, simple_test, .init = redirect_all_std)
{
    save_list_t *s_list = create_test_saved_list();

    cr_assert(s_list);
    display_chained_list(s_list, " -> ");
    cr_assert_stdout_eq_str("lal -> lol -> ");
}
