/*
** EPITECH PROJECT, 2019
** C lib
** File description:
** my_str_split
*/

#include <stddef.h>
#include <malloc.h>
#include <unistd.h>
#include <stdio.h>

static int nullify_to(void *tabptr, size_t limit, int do_free)
{
    void **tab = (void**)(tabptr);
    size_t i = 0;

    if (!tabptr)
        return (-1);
    while (i != limit + 1) {
        if (do_free == 1)
            free(tab[i]);
        tab[i] = NULL;
        ++i;
    }
    if (i == 0 && do_free == 1)
        free(tab);
    return (0);
}

static size_t count_line(char *str, char c)
{
    size_t i = 0;
    size_t nbr_char = 0;

    while (str && str[i] != '\0') {
        if (str[i] == c) {
            ++nbr_char;
            while (str[i++] == c);
        }
        ++i;
    }
    return (nbr_char + 1);
}

static size_t word_len(char *str, size_t pos, char c)
{
    size_t i = 0;

    while (str[pos] != c && str[pos] != '\0') {
        ++pos;
        ++i;
    }
    return (i);
}

static char *copy_word(char *str, size_t *pos, char c)
{
    size_t len_word = word_len(str, *pos, c);
    char *word = malloc(sizeof(char) * (len_word + 1));
    size_t i = 0;

    if (!word || !str) {
        free(word);
        return (NULL);
    }
    word[len_word] = '\0';
    while (i != len_word) {
        word[i] = str[*pos];
        ++i;
        *pos += 1;
    }
    return (word);
}

char **my_str_split(char *str, char c)
{
    size_t nbr_line = count_line(str, c);
    char **tab = malloc(sizeof(char *) * (nbr_line + 1));
    size_t x = 0;
    size_t y = 0;

    if ((nullify_to(tab, nbr_line, 0) == -1) || !str) {
        free(tab);
        return (NULL);
    }
    while (str && str[x] != '\0') {
        while (str[x] == c && str[x + 1] != '\0')
            ++x;
        if ((tab[y] = copy_word(str, &x, c)) == NULL) {
            nullify_to(tab, y, 1);
            free(tab);
            return (NULL);
        }
        ++y;
        ++x;
    }
    return (tab);
}
