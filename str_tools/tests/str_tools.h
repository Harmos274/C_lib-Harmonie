/*
** EPITECH PROJECT, 2019
** header test
** File description:
** header str_tools
*/

#ifndef STR_TOOLS_H_
#define STR_TOOLS_H_

#include <stddef.h>
#include <unistd.h>

void clean_str(char *str);
int my_getnbr(char const *str);
char *my_itoa(int nbr);
void my_put_base_nbr(int nb, char *base);
void my_putstr(char *str);
char *my_revstr(char *str);
int my_char_isnum(char c);
int my_char_isalpha(char c);
int my_str_isnum(char const *c);
int my_str_isalpha(char const *c);
char **my_str_to_word_array(char *str, char d, int prefix);
int my_strcomp(char *source, char *compared);
char *my_strconc(char *left, char *right);
ssize_t my_strlen(char const *str);
void my_str_rewrite(char **source, char *rew, size_t len);
void my_strncpy(char *dest, char *src, size_t n);
char *my_strdup(char const *str);

#endif /*STR_TOOLS_H_*/
