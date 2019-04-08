/*
** EPITECH PROJECT, 2019
** C lib
** File description:
** chained_list_tools header
*/

#ifndef CHAINED_LIST_TOOLS_H_
    #define CHAINED_LIST_TOOLS_H_

    typedef struct save_list_s save_list_t;
    typedef struct chained_list_s chained_list_t;

    struct chained_list_s {
        char *str;
        chained_list_t *next;
    };

    struct save_list_s {
        chained_list_t *list;
        int nbr_chain;
    };

    int add_start_chain(save_list_t *s_list, char *str);
    int add_last_chain(save_list_t *s_list, char *str);
    save_list_t *create_saved_list(void);
    void display_chained_list(save_list_t *s_list, char *delim);

#endif /* !CHAINED_LIST_TOOLS_H */
