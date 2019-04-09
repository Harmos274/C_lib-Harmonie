/*
** EPITECH PROJECT, 2018
** my_str_isalpha
** File description:
** my_str_isalpha
*/

int my_char_isalpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    return (0);
}

int my_str_isalpha(char const *str)
{
    int e = 0;

    while (str[e] != '\0') {
        if (my_char_isalpha(str[e]) == 1)
            ++e;
        else
            return (0);
    }
    return (1);
}
