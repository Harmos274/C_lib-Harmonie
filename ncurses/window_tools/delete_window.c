/*
** EPITECH PROJECT, 2018
** SOURCES // NCURSES
** File description:
** interface.c
*/

#include <curses.h>
#include <stddef.h>
#include <stdarg.h>

void varia_delwin(const size_t nbr_window, ...)
{
    size_t i = 0;
    va_list windows;
    int err_val = 0;

    va_start(windows, nbr_window);
    while (i != nbr_window && err_val != ERR) {
        err_val = delwin(va_arg(windows, WINDOW *));
        ++i;
    }
    va_end(windows);
}
