/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** Contains functions used to handle instructions arguments
*/

#include <unistd.h>

size_t reverse_uint_bits(size_t num)
{
    size_t count = sizeof(num) * 8 - 1;
    size_t reverse_num = num;

    num >>= 1;
    while(num)
    {
       reverse_num <<= 1;
       reverse_num |= num & 1;
       num >>= 1;
       --count;
    }
    reverse_num <<= count;
    return reverse_num;
}

void print_bits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char *)ptr;
    unsigned char byte;
    int i = 0;
    int j = 0;

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = (b[i] >> j) & 1;
            write(1, &byte, sizeof(unsigned char));
        }
    }
    write(1, "\n", sizeof(char));
}

int rev_int_octets(int nbr)
{
    size_t int_size = sizeof(int);
    unsigned char container_tab[int_size];
    int shifter = 8 * (int_size - 1);
    int ret = 0;
    size_t i = 0;

    while (i != int_size) {
        container_tab[i] = nbr >> shifter;
        shifter -= 8;
        ++i;
    }
    i = 0;
    shifter = 0;
    while (i != int_size) {
        ret |= ((int)container_tab[i] << shifter);
        shifter += 8;
        ++i;
    }
    return (ret);
}
