/*
** EPITECH PROJECT, 2018
** SOURCES // NCURSES
** File description:
** interface.c
*/

#include <stdarg.h>
#include <stddef.h>
#include <curses.h>

void varia_wrefresh(const size_t nbr_window, ...)
{
    size_t i = 0;
    va_list windows;
    int err_val = 0;

    va_start(windows, nbr_window);
    while (i != nbr_window && err_val != ERR) {
        err_val = wrefresh(va_arg(windows, WINDOW *));
        ++i;
    }
    va_end(windows);
}
