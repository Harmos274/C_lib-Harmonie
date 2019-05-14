/*
** EPITECH PROJECT, 2019
** C_lib
** File description:
** my_frpintf
*/

#include <stdio.h>
#include <malloc.h>
#include <stdarg.h>
#include "./include/my_fprintf_main_header.h"
#include "./include/str_tools.h"
#include "./include/chain_tools.h"

int add_char_buffer(buffer_list_t *buffers, va_list va)
{
    char ch = va_arg(va, int);

    add_last_ch_chain(buffers, ch);
    return (0);
}

int add_string_buffer(buffer_list_t *buffers, va_list va)
{
    char *str = va_arg(va, char *);

    add_last_str_chain(buffers, str);
    return (0);
}

int add_int_buffer(buffer_list_t *buffers, va_list va)
{
    int nbr = va_arg(va, int);
    char *nstr = my_itoa(nbr);

    if (!nstr)
        return (-1);
    add_last_str_chain(buffers, nstr);
    free(nstr);
    return (0);
}

int add_arg_buffer(buffer_list_t *buffers, va_list va, const char *ch)
{
    char *flag = "csd\0";
    int (*ptr[3])(buffer_list_t *, va_list) = {&add_char_buffer,
        &add_string_buffer, &add_int_buffer};
    ssize_t chcomp = my_charcomp(*ch, flag);

    if (chcomp == -1 || ptr[chcomp](buffers, va) == -1)
        return (-1);
    return (0);
}

int add_str_buffer(buffer_list_t *buffers, const char *str, size_t *i)
{
    ssize_t len = my_strlen(str, '%');
    char buff[len + 1];

    *i += len;
    if (len == -1)
        return (-1);
    buff[len] = '\0';
    my_strncpy(str, buff, len);
    add_last_str_chain(buffers, buff);
    return (0);
}

int fill_save_buffer(buffer_list_t *buffers, va_list va, const char *str)
{
    size_t i = 0;

    while (str[i] != '\0') {
        if (str[i] == '%') {
            if (add_arg_buffer(buffers, va, str + i + 1) == -1)
                return (-1);
            i += 2;
        } else {
            if (add_str_buffer(buffers, str + i, &i) == -1)
                return (-1);
        }
    }
    return (0);
}

buffer_list_t *get_buffer(va_list va, const char *str)
{
    buffer_list_t *buffers = malloc(sizeof(*buffers));

    if (buffers) {
        buffers->list = NULL;
        buffers->nbr_chain = 0;
        if (fill_save_buffer(buffers, va, str) == -1)
            return (NULL);
    }
    return (buffers);
}

static int print_buffer_to_stream(FILE *stream, buffer_list_t *buffers)
{
    chained_list_t *discover = buffers->list;

    while (discover != NULL) {
        fwrite(discover->str, sizeof(char), discover->len, stream);
        discover = discover->next;
    }
    return (0);
}

ssize_t my_fprintf(FILE *stream, const char *str, ...)
{
    va_list va;
    size_t len = 0;
    buffer_list_t *buffers = NULL;

    if (str) {
        va_start(va, str);
        buffers = get_buffer(va, str);
        if (!buffers || print_buffer_to_stream(stream, buffers) == -1) {
            va_end(va);
            return (-1);
        }
        supr_all_elements(buffers);
        free(buffers);
        va_end(va);
    }
    return (len);
}

int main(void)
{
    my_fprintf(stdout, "%s\n%s\n  aaefdsf%d%c\0", "bonsoir\0", "coucou\0", 10, 'c');
    return (0);
}
