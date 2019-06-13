/*
** EPITECH PROJECT, 2018
** SOURCES // NCURSES
** File description:
** interface.c
*/

#include <curses.h>
#include "./tests/window_struct.h"
#include "../../str_tools/tests/str_tools.h"

window_prop_t make_w_prop(size_t h, size_t w, size_t s_y, size_t s_x)
{
    window_prop_t w_prop = {h, w, s_y, s_x};
    return (w_prop);
}

WINDOW *create_window(window_prop_t w_prop, char *border)
{
    WINDOW *new_win = NULL;

    new_win = newwin(w_prop.height, w_prop.width, w_prop.start_y,
        w_prop.start_x);
    if (!border)
        box(new_win, ACS_VLINE, ACS_HLINE);
    else if (my_strlen(border) >= 8){
        wborder(new_win, border[0], border[1], border[2], border[3],
            border[4], border[5], border[6], border[7]);
    }
    return (new_win);
}

WINDOW *create_sub_window(WINDOW *origin, window_prop_t w_prop, char *border)
{
    WINDOW *new_win = NULL;

    new_win = subwin(origin, w_prop.height, w_prop.width, w_prop.start_y,
        w_prop.start_x);
    if (!border)
        box(new_win, ACS_VLINE, ACS_HLINE);
    else if (my_strlen(border) >= 8) {
        wborder(new_win, border[0], border[1], border[2], border[3],
            border[4], border[5], border[6], border[7]);
    }
    return (new_win);
}
