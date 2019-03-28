/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_putstr
*/

#include "./tests/str_tools.h"
#include <unistd.h>

void my_putstr(char *str)
{
    if (!str)
        return ;
    write(1, str, my_strlen(str));
}
