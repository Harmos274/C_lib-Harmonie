/*
** EPITECH PROJECT, 2019
** C lib
** File description:
** variadic free
*/

#include <stdarg.h>
#include <malloc.h>
#include <stddef.h>
#include "../chained_list_tools/tests/chained_list_tools.h"
#include "../tab_tools/tests/tab_tools.h"

void free_list(va_list va)
{
    save_list_t *s_list = va_arg(va, save_list_t *);

    supr_save_list(&s_list);
}

void free_tab(va_list va)
{
    char **tab = va_arg(va, char **);

    nullify_from(tab, 0, 1);
    free(tab);
    tab = NULL;
}

void free_str(va_list va)
{
    char *str = va_arg(va, char *);

    free(str);
    str = NULL;
}

static size_t my_charcomp(char c, char *comp)
{
    size_t i = 0;

    while (comp[i] != '\0' && c != comp[i])
        ++i;
    return (i);
}

void varia_free(char *opt, ...)
{
    va_list va;
    void (*ptr[3])(va_list) = {&free_str, &free_tab, &free_list};
    size_t i = 0;

    va_start(va, opt);
    while (opt[i] != '\0') {
        ptr[my_charcomp(opt[i], "stl\0")](va);
        ++i;
    }
    va_end(va);
}
