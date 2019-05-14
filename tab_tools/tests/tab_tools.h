/*
** EPITECH PROJECT, 2019
** header test
** File description:
** header str_tools
*/

#ifndef TAB_TOOLS_H_
#define TAB_TOOLS_H_

#include <unistd.h>

ssize_t my_strlen(char const *str);
char *my_strdup(char const *str);
void nullify_from(void *tab, size_t i, int do_free);
ssize_t my_tablen(char **tab);
void printab(char **tab);
char **tab_set(const size_t x, const size_t y, char c);

#endif /*TAB_TOOLS_H_*/
