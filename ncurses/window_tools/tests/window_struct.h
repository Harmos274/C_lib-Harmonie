/*
** EPITECH PROJECT, 2019
** C lib
** File description:
** chained_list_tools header
*/

#ifndef WINDOW_STRUCT_H_
    #define WINDOW_STRUCT_H_

    #include <stddef.h>

    typedef struct window_prop_s window_prop_t;
    struct window_prop_s {
        const size_t height;
        const size_t width;
        const size_t start_y;
        const size_t start_x;
    };

#endif /* !WINDOW_STRUCT_H_ */
