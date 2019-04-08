/*
** EPITECH PROJECT, 2018
** my_str_token_split.c
** File description:
** show word array
*/

#include "./tests/str_tools.h"
#include <malloc.h>

////////////////////////////////////////// TOKEN STRUCT /////////////////////////////////////////
#ifndef STRUCT_H
#define STRUCT_H

    typedef struct saved_tokens_s saved_tokens_t;
    typedef struct token_list_s token_list_t;

    struct token_list_s {
        char *token;
        token_list_t *next;
    };

    struct saved_tokens_s {
        token_list_t *first_mode;
        token_list_t *second_mode;
    };

#endif /* !STRUCT_H */
///////////////////////////////////////////////////////////////////////////////////////////////////

saved_tokens_t *alloc_toklist(void)
{
    saved_tokens_t *tok_list = malloc(sizeof(*tok_list));

    tok_list->first_mode = NULL;
    tok_list->second_mode = NULL;
    return (tok_list);
}

void add_first_mode(saved_tokens_t *tok_list, char *token)
{
    token_list_t *toky = malloc(sizeof(*toky));

    toky->token = my_strdup(token);
    if (!tok_list) {
        free(toky);
        return ;
    }
    if (tok_list->first_mode == NULL) {
        tok_list->first_mode = toky;
        tok_list->first_mode->next = NULL;
    } else {
        toky->next = tok_list->first_mode;
        tok_list->first_mode = toky;
    }
}

void add_second_mode(saved_tokens_t *tok_list, char *token)
{
    token_list_t *toky = malloc(sizeof(*toky));

    toky->token = my_strdup(token);
    if (!tok_list) {
        free(toky);
        return ;
    }
    if (tok_list->second_mode == NULL) {
        tok_list->second_mode = toky;
        tok_list->second_mode->next = NULL;
    } else {
        toky->next = tok_list->first_mode;
        tok_list->second_mode = toky;
    }
}

saved_tokens_t *make_tokens_list(char **params)
{
    saved_tokens_t *tok_list = alloc_toklist();
    void(*ptr[2])(saved_tokens_t *, char *) = {&add_first_mode, &add_second_mode};
    size_t i = 0;

    while (params && params[i] != NULL) {
        ptr[params[i][0] - '1'](tok_list, params[i]);
        ++i;
    }
    return (tok_list);
}

char **my_str_token_plit(char *str, char *token)
{
    char **params = my_str_to_word_array(str, ' ', 0);
    saved_tokens_t *tokens = make_tokens_list(params);
    char **tab = NULL;
    size_t i = 0;

    nullify_from(params, 0, 1);
    free(params);
    return (tab);
}
